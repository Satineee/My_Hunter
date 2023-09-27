const http = require('http');
const fs = require('fs');
const path = require('path');
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
    } else if (req.url === '/') {
        const filePath = path.join(__dirname, 'index.html');
        fs.readFile(filePath, 'utf8', (err, data) => {
            if (err) {
                console.error(`Erreur lors de la lecture du fichier : ${err.message}`);
                res.statusCode = 500;
                res.end('Erreur lors de la lecture du fichier.');
                return;
            }
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.end(data);
        });
    } else {
        res.statusCode = 404;
        res.end('Page non trouvée.');
    }
});

server.listen(3000, () => {
    console.log('Serveur démarré sur le port 3000');
});
