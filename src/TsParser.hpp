#pragma once

#include "Parser.hpp"

class QDomNode;

class TsParser : public Parser
{
  public:
    explicit TsParser(InOutParameter parameter);

    std::pair<Translations, QString> parse() const override;

  private:
    std::pair<QString, int> wrapLocation(const QDomNode &node) const;
};
