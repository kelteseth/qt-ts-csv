#include "TsBuilder.hpp"

#include <QtXml>

TsBuilder::TsBuilder(InOutParameter parameter) : Builder{ std::move(parameter) }
{
}

bool TsBuilder::build(const Translations &trs) const
{
    const auto outputFile = m_ioParameter.outputDir + "/output.ts";
    QFile output(outputFile.c_str());
    if (!output.open(QFile::WriteOnly | QFile::Truncate)) {
        qDebug() << "can't open file" << output.fileName();
        return false;
    }

    QDomDocument doc("TS");

    auto root = doc.createElement("TS");
    root.setAttribute("version", "2.1"); // TODO: extract as parameter

    for (const auto &ctxs : trs) {
        auto context = doc.createElement("context");
        auto name    = doc.createElement("name");
        name.appendChild(doc.createTextNode(ctxs.name));
        context.appendChild(name);

        for (const auto msg : ctxs.messages) {
            auto message = doc.createElement("message");
            for (auto loc : msg.locations) {
                auto location = doc.createElement("location");
                location.setAttribute("line", loc.second);
                location.setAttribute("filename", loc.first);
                message.appendChild(location);
            }

            auto source = doc.createElement("source");
            source.appendChild(doc.createTextNode(msg.source));
            message.appendChild(source);

            auto translation = doc.createElement("translation");
            translation.appendChild(doc.createTextNode(msg.translation));
            message.appendChild(translation);
            context.appendChild(message);
        }

        root.appendChild(context);
    }

    doc.appendChild(root);
    doc.normalize();

    QTextStream stream(&output);
    stream << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    stream << doc.toString(2);

    output.close();
    return true;
}
