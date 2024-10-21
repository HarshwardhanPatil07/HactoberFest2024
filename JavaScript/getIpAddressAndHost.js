/*

username : ankitjhagithub21
aim : full stack web developer

*/

// Import the os module
const os = require('os');

// Function to get IP address and hostname
function getIPAddressAndHostname() {
    // Get the hostname
    const hostname = os.hostname();

    // Get the network interfaces
    const networkInterfaces = os.networkInterfaces();

    // Filter for IPv4 addresses
    let ipAddress;
    for (const interfaceName in networkInterfaces) {
        for (const interfaceDetails of networkInterfaces[interfaceName]) {
            if (interfaceDetails.family === 'IPv4' && !interfaceDetails.internal) {
                ipAddress = interfaceDetails.address;
                break;
            }
        }
        if (ipAddress) break; // Exit if we found an IP address
    }

    // Print the hostname and IP address
    console.log(`Hostname: ${hostname}`);
    console.log(`IP Address: ${ipAddress || 'No external IP found'}`);
}

// Call the function
getIPAddressAndHostname();




