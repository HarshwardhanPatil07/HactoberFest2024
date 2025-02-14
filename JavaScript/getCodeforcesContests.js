// Function to fetch and display upcoming Codeforces contests
async function displayUpcomingContests() {
    try {
        // Fetch the list of contests from the Codeforces API
        const response = await fetch('https://codeforces.com/api/contest.list');
        const data = await response.json();

        // Check if the API response is successful
        if (data.status !== 'OK') {
            console.error('Failed to fetch contests:', data.comment);
            return;
        }

        // Get the current time in milliseconds
        const currentTime = Date.now();

        // Filter for upcoming contests
        const upcomingContests = data.result.filter(contest => {
            const contestStartTime = contest.startTimeSeconds * 1000;
            return contestStartTime > currentTime;
        });

        // Sort the upcoming contests by start time
        upcomingContests.sort((a, b) => a.startTimeSeconds - b.startTimeSeconds);

        // Get the next two upcoming contests
        const nextTwoContests = upcomingContests.slice(0, 2);

        // Display the contest details
        nextTwoContests.forEach(contest => {
            const startDate = new Date(contest.startTimeSeconds * 1000);
            console.log(`Contest: ${contest.name}`);
            console.log(`Date: ${startDate.toLocaleDateString()}`);
            console.log(`Start Time: ${startDate.toLocaleTimeString()}`);
            console.log('---');
        });
    } catch (error) {
        console.error('Error fetching contests:', error);
    }
}

// Call the function to display upcoming contests
displayUpcomingContests();
