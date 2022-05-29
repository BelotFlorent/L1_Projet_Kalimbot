*******************
<h1>Cahier de suivi du projet de Florent BELOT</h1>
<br/><br/>

*******************

* **Séance du 11 mars** :

<p1>  Pour ce projet, durant les séances de TP prévues pour celui-ci, nous avons réfléchis à différents types de projets que nous pouvions réaliser. Nous nous sommes tous mis d'accord pour partir dans le thème de la musique (on souhaitait faire un projet à la fois utilitaire et divertissant). Pour ce projet, il nous fallait un instrument assez compact (amener un piano pour le projet allait être compliqué), c'est pourquoi nous avons décider de travailler sur un Kalimba. Nous avons réfléchis à plusieurs possibilitées pour bien faire fonctionner le Kalimbot. On a donc décidé de mettre un moteur par note, sur les 8 notes les plus jouées du kalimba. Notre idée globale du projet était donc terminée, et nous avons décidé de répartir les tâches en 2 groupes : Florent qui allait s'occuper de la partie code du projet, Alexis et Shanti qui allaient s'occuper de toute la partie physique et de la mise en forme du Kalimbot.</p1>

*******************

* **Samedi 23 Avril** :

<p1>  Pour commencer mon premier objectif était de réussir a faire communiquer les deux cartes, celle qui servira de télécommande et celle receptrice qui servira a faire fonctionner les servomoteurs. Je suis donc parti des codes dont nous nous étions servi en TP permettant de communiquer en peer to peer entre deux cartes en LoRa. J'ai réussi sans trop de problème grâce au tp. La deuxième étape était d'envoyer un message pouvant être utilisé dans le code de la deuxième carte et pas seulement affiché dans le terminal, il ma fallu un peu de temps pour comprendre qu'il fallait utiliser la boucle "while (LoRa.available())", ensuite il a juste fallu mettre des "if" et "else if".
  Ensuite mon second objectif était de réussir a faire bouger un servomoteur. J'ai eu un peu plus de mal a faire ça, bien que nous avions déjà fait bouger les servomoteurs en tp je ne me souvennais plus trop du fonctionnement du code, surtout que pour arranger le tout j'étais tombé sur le seul servomoteurs qui était défaillant. Avec un peu d'aide j'ai finallement reussi à comprendre le fonctionnement du code pour les servomoteurs.
  Et pour finir j'ai fusionner le tout pour permettre de faire bouger 2 servomoteurs en fonction du message envoyé (1 ou 2), cela marchait mais c'était très lent environ un mouvement toute les 2 secondes.
</p1>

*******************

* **Jeudi 12 mai** :

<p1>  Mon objectif du jour était de reussir a utiliser un maximum de servomoteurs en même temps. Malheureusement je manquais de file et je ne pouvais brancher que 4 servomoteurs maximum. Donc j'ai modifier le code pour rajouter 2 servomoteurs par rapport à l'ancien code. Mais il fallait quand même voir quel était les ports qui fonctionnait, après avoir fait plusieurs test j'ai reussi a trouver 10 ports que l'on pouvait utiliser pour les servomoteurs. Mais pour brancher tout les servomoteurs j'étais obligé de passer par une breadboard parce qu'il n'y avait qu'un seul port V_BUS pour l'alimentation et pas assez de GND pour notre objectif de 8 notes.
</p1>

*******************

* **Samedi 21 mai** :

<p1>  Aujourd'hui l'objectif était de reussir à jouer le début de "Au clair de la Lune" avec 3 servomoteurs. Dans un premier temps j'étais partie sur le principe d'envoyer une note à la fois avec la "télécommande" qui n'en était pas encore une, grâce à une boucle. Le problème de cette solution c'est qu'il était impossible de jouer rapidement les notes parce que cela prend du temps d'envoyer et de recevoir un message. Si l'on veut avoir une musique fluide ce n'est pas pratique. Donc après un petit moment de refléxion me vient l'idée toute simple d'envoyer la suite de note à jouer sous forme d'un seul message en une suite de caractère et d'utiliser une boucle dans le code de la carte réceptrice ce qui était bien plus pratique pour stocker et envoyer plusieurs musique sans problème. Du coup après avoir écrit le code j'ai donc rentrer la suite "1112302013221" correspondant au début de "Au clair de la Lune", et tout marcha avec une vitesse correct.
</p1>

*******************

* **Lundi 23 mai** Séance au fablab :

<p1>  Aujourd'hui nous nous sommes tous retrouvé au fablab et j'ai pu récuperer les files manquants pour pouvoir brancher les 8 servomoteurs en même temps, donc j'ai modifier le code pour qu'il puisse utiliser 8 servomoteurs en même temps, j'ai tout brancher (ce qui ma pris en certains temps), et puis j'ai tester le code avec d'autre musqiue pour voir si tout marchait bien, et tout a bien marché.
  Mon nouvelle objectif était donc de pouvoir utiliser l'écran fourni avec les cartes qui servira pour la télécommande. Je n'ais pas vraiment réussi et la fablab allait fermé donc j'ai attendu le lendemain pour le faire.
</p1>

*******************

* **Mardi 24 mai** Séance au fablab :

<p1>  Aujourd'hui mon objectif est de réaliser la télécommande avec les boutons et l'écran foncitonnelle. Dans un premier temps j'ai préférer faire fonctionner les boutons, donc avec plusieurs essai de code j'ai reussi a faire marcher les 3 boutons, ensuite il a fallu que je réussisse a faire marcher l'écran, grâce à l'exemple du cours cela n'a pas été trop compliqué. Ensuite j'ai modifier le code de la télécommande qui en devient enfin une. J'ai donc rajouter les boutons et l'écrans. Le problème que j'ai eu était ensuite qu'il ne m'était pas possible de mettre des variables dans la fonction pour l'affichage sur l'écran du coup au final j'ai juste fait des conditions avec plein de "if" pour chanque musique. J'ai donc réussi a faire la télécommande. Le dernier détail était de l'utiliser avec une batterie mais cela n'a pas été très compliqué parce que le professeur m'avait expliquer comment m'en servir.
  J'ai donc réussi a faire la télécommande et le code qui receptionne les messages et permet de jouer les partitions, ma partie du projet était terminé à quelque détails prêt.
</p1>

*******************

* **Mercredi 25 mai** Séance au fablab :

<p1>
</p1>
