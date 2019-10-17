[![Build Status](https://travis-ci.org/guerinoni/qt-ts-csv.svg?branch=master)](https://travis-ci.org/guerinoni/qt-ts-csv)

# qt-ts-csv
A tool to generate csv file from qt ts file and vice versa

## Build
~~~
before_install:
  - sudo add-apt-repository --yes ppa:beineri/opt-qt-5.12.3-bionic
  - sudo apt-get update -qq

install:
  - sudo apt-get -y install cmake
  - sudo apt-get -y install libgl1-mesa-dev
  - sudo apt-get -y install qt512base
  - sudo apt-get -y install qt512quickcontrols
  - sudo apt-get -y install qt512quickcontrols2

script:
  - source /opt/qt512/bin/qt512-env.sh
  - mkdir build
  - cd build
  - cmake .. -DCMAKE_PREFIX_PATH=/opt/qt512/
  - make
~~~

## Usage

### To generate output.csv  
![example conversion ts -> csv](./doc/Screenshot.png)  

