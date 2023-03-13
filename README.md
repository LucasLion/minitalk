# Description de `minitalk`

`minitalk` est un projet en C que j'ai codé pour l'école 42. C'est un programme client-serveur qui permet de transmettre des messages entre deux processus à travers des signaux Unix.

Le but de ce projet est de mettre en pratique les connaissances en programmation en C et en système Unix, ainsi que de comprendre le fonctionnement des signaux Unix.

## Utilisation

Pour utiliser le programme `minitalk`, il faut d'abord le compiler en utilisant la commande `make` dans le terminal. Ensuite, il faut exécuter le programme serveur en fournissant son PID comme argument, par exemple :

``` sh
./server PID
```

Le serveur est maintenant en attente de messages à recevoir. Pour envoyer un message, il faut exécuter le programme client en fournissant le PID du serveur et le message à envoyer comme arguments, par exemple :

``` sh
./client PID "Hello world"
```

Le message "Hello world" est alors envoyé au serveur, qui l'affiche dans la sortie standard.

## Fonctionnement

Le programme `minitalk` utilise des signaux Unix pour transmettre des messages entre les processus. Le serveur utilise la fonction `sigaction` pour intercepter les signaux `SIGUSR1` et `SIGUSR2`, et utilise la fonction `kill` pour envoyer un signal de confirmation au client une fois qu'il a reçu un message.

Le client utilise la fonction `kill` pour envoyer des signaux au serveur, en envoyant un signal SIGUSR1 pour chaque bit de 1 dans le message, et un signal SIGUSR2 pour chaque bit de 0. Une fois que le serveur a reçu tous les signaux, il reconstruit le message et l'affiche dans la sortie standard.

## Conclusion

`minitalk` est un projet intéressant qui permet de mieux comprendre le fonctionnement des signaux Unix et de mettre en pratique les connaissances en programmation en C et en système Unix. Le programme client-serveur est simple mais efficace, et peut être utilisé pour transmettre des messages entre deux processus sur une même machine. Le projet est disponible sur la plateforme GitHub de l'école 42 et peut être amélioré pour ajouter de nouvelles fonctionnalités ou pour optimiser les fonctions existantes.

