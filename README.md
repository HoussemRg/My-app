# My-app
On se propose de concevoir une application pour la gestion du personnel d’un centre de 
formation. Une collecte d’informations nous a fourni les données suivantes : 
- Chaque employé a un nom et est identifié par le même numéro de matricule tout au long de sa carrière. Chaque employé doit être capable de calculer son salaire . 
- Un employé peut être soit un agent administratif, soit un enseignant.
- Un enseignant a obligatoirement une spécialité (string) et une charge horaire à enseigner par semaine (charge de 10h si aucune information n’est communiquée). Son salaire est égal à la charge horaire mensuelle multipliée par 25 dt.
- Un agent administratif peut être un directeur, un chef de département ou un fonctionnaire.
- Un agent administratif est caractérisé par son nombre d'années d'ancienneté
- Un chef de département est aussi un enseignant, mais qui perçoit en plus une prime de 200 dt par mois.
- Le directeur et les fonctionnaires perçoivent respectivement 1000 dt et 500 dt auxquels s'ajoutent 30 dt par année d'ancienneté.
