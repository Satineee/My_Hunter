
document.getElementById("startButton").addEventListener("click", function() {
    // Utilisez Node.js pour exécuter le script JavaScript
    const { exec } = require('child_process');
    const command = 'node run_game.js';

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
});