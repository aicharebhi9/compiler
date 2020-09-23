# compiler
The procedure to follow :
  1.Create a .bat file and name it RUN with .bat extension (RUN.bat)
  2. Write the following lines of code:
      flex flex.l
      bison -d bison.y
      gcc lex.yy.c bison.tab.c -o compilM1
      compilM1
  3.After inserting in the project folder (HAMRAOUI_REBHI_G2 / Source code), execute the command line 'CMD'
  4.Execute the RUN command
  5.There will be a display, choose your choice
  6.If you want to resume the display, run the command copmilM1
  
  #compilateur 
  
  La procédure à suivre :
  1.Creer un fichier .bat et le nomé RUN avec extention .bat (RUN.bat)
  2.Ecrire les ligne de code suivantes :
      flex flex.l
      bison -d bison.y
      gcc lex.yy.c bison.tab.c -o compilM1
      compilM1
  3.Après l'empalcement dans le dossier du projet (HAMRAOUI_REBHI_G2/Code source), executer la ligne de commande 'CMD'
  4.Executer la commande RUN
  5.Il y'aura un affichage, choisissez votre choix
  6.Si vous voulez reprendre l'affichage, exécuter la commande copmilM1
