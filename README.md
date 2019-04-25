# Clonium

## Principe du jeu : 
Clonium est un jeu de plateau qui se joue de 2 à 4 joueurs. 

## But du jeu : 
Capturer tous les pions de l'adversaire. Le dernier joueur à qui il reste des pions a gagné. 

## Règles du jeu : 
Le plateau de jeu est un échiquier qui carré qui comporte entre 6 et 10 cases de large, en fonction de la durée de la partie souhaitée. Chaque équipe possède des pions de sa couleur. Un pion peut être de niveau 1, 2, 3 ou 4. Il ne peut pas se déplacer, mais on peut augmenter son niveau. Un tour de jeu consiste donc à augmenter le niveau d'un de ses pions. Une fois le niveau 3 atteint, une augmentation de son niveau au niveau 4 entraînera immédiatement une scission en 4 pions de niveau 1 qui se placeront dans les cases adjacentes, latéralement et verticalement (pas en diagonale). Si des pions sont présents dans les cases en question : - S'ils appartiennent à une équipe adverse on les capture, - Dans tous les cas, on augmente leur niveau de 1. Ceci peut entraîner des réactions en chaîne. Lorsque plusieurs pions déclenchent une réaction en chaîne, il peut y avoir plusieurs cases qui sont activées simultanément. On adoptera donc une gestion « tour par tour » des réactions en chaîne.  

## Déroulement d'une partie : 
Les joueurs commencent la partie en choisissant un coin. On leur attribue ensuite un pion de niveau 3 dans la case située à une case de distance de chaque bord qui constitue leur coin (case B2, B7, G2 ou G7 aux échecs). Chaque joueur jouera à son tour, en commençant par le joueur au coin inférieur gauche, puis en tournant dans le sens inverse des aiguilles d'une montre. Les joueurs jouent donc chacun leur tour tant qu'ils ont au moins un pion, et le dernier joueur à qui il reste au moins un pion est le vainqueur de la partie. 

