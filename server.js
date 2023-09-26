const http = require('http');
const { exec } = require('child_process');

const server = http.createServer((req, res) => {
    if (req.url === '/startGame') {
        const command = 'node run_game.js';

        exec(command, (error, stdout, stderr) => {
            if (error) {
                console.error(`Erreur lors de l'exécution du jeu : ${error.message}`);
                res.statusCode = 500;
                res.end('Erreur lors de l\'exécution du jeu.');
                return;
            }
            if (stderr) {
                console.error(`Erreur lors de l'exécution du jeu : ${stderr}`);
            }
            console.log(`Le jeu a été lancé avec succès : ${stdout}`);
            res.end('Le jeu a été lancé avec succès.');
        });
    } else {
        res.statusCode = 404;
        res.end('Page non trouvée.');
    }
});

server.listen(3000, () => {
    console.log('Serveur démarré sur le port 3000');
});
