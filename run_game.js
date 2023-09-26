const { exec } = require('child_process');

// Commande pour exécuter votre fichier exécutable C
const command = './my_hunter';

exec(command, (error, stdout, stderr) => {
    if (error) {
        console.error(`Erreur lors de l'exécution du jeu : ${error.message}`);
        return;
    }
    if (stderr) {
        console.error(`Erreur lors de l'exécution du jeu : ${stderr}`);
        return;
    }
    console.log(`Le jeu a été lancé avec succès : ${stdout}`);
});
