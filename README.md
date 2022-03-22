########Required-Installations for linux##########
----------------------
QT installation:
----------------------
sudo apt-get install qtbase5-dev

----------------------
Sodium installation:
----------------------
download latest version from https://download.libsodium.org/libsodium/releases/
inside the extracted folder:
./configure
make && make check
sudo make install
###########Required-Installations for mac###########
----------------------
QT installation:
----------------------
brew install qt5
cmake -D CMAKE_PREFIX_PATH=/Users/<username>/.../Qt/.../lib/cmake ..

----------------------
Sodium installation:
----------------------
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
brew install libsodium
##########Compile-Instructions##########
cd build
cmake ..
make
./IBR_COIN

