import requests
import matplotlib.pyplot as plt

# GitHub API URL
BASE_URL = "https://api.github.com"

def fetch_repo_data(username):
    """Fetch repository data for a given GitHub username."""
    url = f"{BASE_URL}/users/{username}/repos"
    response = requests.get(url)

    if response.status_code == 200:
        return response.json()
    else:
        print("Failed to fetch data:", response.status_code)
        return []

def visualize_repo_stats(repos):
    """Visualize repository stats like stars and forks."""
    names = [repo['name'] for repo in repos]
    stars = [repo['stargazers_count'] for repo in repos]
    forks = [repo['forks_count'] for repo in repos]

    fig, ax = plt.subplots(2, 1, figsize=(10, 8))
    fig.suptitle("GitHub Repository Stats")

    # Plotting stars
    ax[0].barh(names, stars, color='blue')
    ax[0].set_title("Stars per Repository")
    ax[0].set_xlabel("Stars")
    ax[0].set_ylabel("Repository")

    # Plotting forks
    ax[1].barh(names, forks, color='green')
    ax[1].set_title("Forks per Repository")
    ax[1].set_xlabel("Forks")
    ax[1].set_ylabel("Repository")

    plt.tight_layout()
    plt.show()

def main():
    username = input("Enter GitHub username: ")
    repos = fetch_repo_data(username)

    if repos:
        visualize_repo_stats(repos)

if __name__ == "__main__":
    main()
