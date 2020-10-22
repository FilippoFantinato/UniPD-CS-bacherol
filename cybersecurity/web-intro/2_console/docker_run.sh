#!/bin/bash
docker run "$@" --rm -h "local-cyber.com" -p "127.0.0.1:8081:80" --name "console" -it "zenhackteam/console"
