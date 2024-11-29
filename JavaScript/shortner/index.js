// Import required modules
const express = require('express');
const shortid = require('shortid');
const app = express();
const port = 3000;

// In-memory storage for URLs
const urlDatabase = {};

// Middleware to parse JSON requests
app.use(express.json());

// Endpoint to create a short URL
app.post('/shorten', (req, res) => {
    const originalUrl = req.body.url;

    // Validate if URL is provided
    if (!originalUrl) {
        return res.status(400).json({ error: 'URL is required' });
    }

    // Generate a unique short ID
    const shortUrl = shortid.generate();

    // Store the original URL with the short URL as key
    urlDatabase[shortUrl] = originalUrl;

    // Return the short URL
    res.json({ originalUrl, shortUrl: `http://localhost:${port}/${shortUrl}` });
});

// Endpoint to redirect to the original URL
app.get('/:shortUrl', (req, res) => {
    const shortUrl = req.params.shortUrl;

    // Look up the original URL
    const originalUrl = urlDatabase[shortUrl];

    if (!originalUrl) {
        return res.status(404).json({ error: 'URL not found' });
    }

    // Redirect to the original URL
    res.redirect(originalUrl);
});

// Start the server
app.listen(port, () => {
    console.log(`URL shortener app listening at http://localhost:${port}`);
});
