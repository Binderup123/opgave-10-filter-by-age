# opgave-10-filter-by-age

dette er et progam som, læser argumenter linje for linje. programmet, læser både linjer i en .csv fil, men fungere også med start argumenter. det som programmet skal, er at kunne læse en linje og tjekke om der er et navn og en alder, hvis der er begge dele, skal den efter tjekke om alderen er inden for max alder. den sortere dem fra som er uden for max alder, og printer det ud som et resultat, inten i terminal, eller i en output.csv fil. 

i koden er dele af koden opgivet, men har arbejdet med kdoen for at få det den til gøre det som den skal

jeg startede med at danne et overblik, dette gjorde jeg ved at skitsere programmet i flowchart, her holdte jeg det simplet, og derfor lavede jeg kun de større kategoriger for at kunne forstå helheden i koden.

filter_stream()
læser en linje ad gangen, og checker om der er nok argumenter / om der er navn og alder i linjen.
samtidig checker denne funktion om alderen givet som argument, er inden for grændserne.


 main()
 håndterer selve programet. Den læser kommandolinjeargumenterne, kontrollerer, at de er gyldige, og åbner input og output filer (eller bruger standard input/output, hvis der ikke er nogen filer). Den udskriver derefter en oversigt over de argumenter, der bruges, og kalder filter_stream() for at behandle dataene. 


