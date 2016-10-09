g++ -std=c++11 portsetter.cpp -o portsetter.o
sudo mv ./portsetter.o /usr/local/bin/setport
if [ ! -d "/files/setport" ]; then
  sudo mkdir ~/files
  sudo mkdir ~/files/setport
fi
sudo cp ./portsetter.about_en.txt /files/setport
sudo cp ./portsetter.usage_en.txt /files/setport 
sudo cp ./portsetter.about_es.txt /files/setport
sudo cp ./portsetter.usage_es.txt /files/setport 
sudo cp ./portsetter.output_en.txt /files/setport
sudo cp ./portsetter.output_es.txt /files/setport
