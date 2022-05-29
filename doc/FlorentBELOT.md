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
  Et pour finir j'ai fusionner le tout pour permettre de faire bouger 2 servomoteurs en fonction du message envoyé (1 ou 2).
</p1>

*******************
