Avvio macchina virtuale:
export EXTERNAL_PORT=10000
vagrant plugin install vagrant-proxyconf (o rimuovere la riga 89 del file Vagrantfile)
vagrant up
vagrant upload docker /home/alpine/docker

Accedere nella macchina virtuale e avviare i servizi docker
vagrant ssh
export EXTERNAL_PORT=10000
cd docker
docker-compose up -d --build --force-recreate

Accedere ai servizi da browser su http://localhost:10000
