#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Achievement;
struct Game;
struct Platform;


class Achievement {
    std::string title;
    std::string description;
    int scoreValue;

public:
    Achievement(const std::string& t, const std::string& d, int sv)
        : title(t), description(d), scoreValue(sv) {}

    // Accessors (getters)
    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
    int getScoreValue() const { return scoreValue; }

    // Mutators (setters)
    void setTitle(const std::string& t) { title = t; }
    void setDescription(const std::string& d) { description = d; }
    void setScoreValue(int sv) { scoreValue = sv; }
};

class Game {
    std::string name;
    std::string publisher;
    std::string developer;
    std::vector<Achievement> achievements;

public:
    Game(const std::string& n, const std::string& p, const std::string& d)
        : name(n), publisher(p), developer(d) {}

    // Accessors
    std::string getName() const { return name; }
    std::string getPublisher() const { return publisher; }
    std::string getDeveloper() const { return developer; }
    const std::vector<Achievement>& getAchievements() const { return achievements; }

    // Mutators
    void setName(const std::string& n) { name = n; }
    void setPublisher(const std::string& p) { publisher = p; }
    void setDeveloper(const std::string& d) { developer = d; }
    void addAchievement(const Achievement& a) { achievements.push_back(a); }
};

class Platform {
    std::string name;
    std::string manufacturer;
    std::vector<Game> games;

public:
    Platform(const std::string& n, const std::string& m)
        : name(n), manufacturer(m) {}

    // Accessors
    std::string getName() const { return name; }
    std::string getManufacturer() const { return manufacturer; }
    const std::vector<Game>& getGames() const { return games; }
    std::vector<Game>& getEditableGames() { return games; }
    // Mutators
    void setName(const std::string& n) { name = n; }
    void setManufacturer(const std::string& m) { manufacturer = m; }
    void addGame(const Game& g) { games.push_back(g); }
};
void displayMainMenu() {
    std::cout << "1. Add Achievement to Game\n";
    std::cout << "2. Display All Games\n";
    std::cout << "3. Exit\n";
}
void addGameToPlatform(Platform& platform);
void addAchievementToGame(Game& game);
void displayPlatforms(const std::vector<Platform>& platforms);
void selectPlatform(std::vector<Platform>& platforms);
void selectGame(std::vector<Game>& games);
void createPlatform(vector<Platform>& platforms);

int main() {
    std::vector<Platform> platforms;

    bool running = true;
    int choice;

    while (running) {
        std::cout << "1. Create Platform\n";
        std::cout << "2. Add Game to Platform\n";
        std::cout << "3. Add Achievement to Game\n";
        std::cout << "4. Display Platforms and Games\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            createPlatform(platforms);
            break;
        }
        case 2:
            selectPlatform(platforms);
            break;
        case 3:
            if (platforms.empty()) {
                std::cout << "No platforms available. Please create a platform first.\n";
                break;
            }
            for (auto& platform : platforms) {
                // Here you call the non-const version of getGames
                selectGame(platform.getEditableGames());
            }
            break;
        case 4:
            displayPlatforms(platforms);
            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
void createPlatform(vector<Platform>& platforms) {
    string name, manufacturer;
    cout << "Enter platform name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter manufacturer: ";
    getline(cin, manufacturer);

    Platform newPlatform(name, manufacturer);
    for (int i = 0; i < 5; ++i) {
        addGameToPlatform(newPlatform);
    }
    platforms.push_back(newPlatform);
}

void addGameToPlatform(Platform& platform) {
    string name, publisher, developer;
    cout << "Enter game name: ";
    getline(cin, name);
    cout << "Enter publisher: ";
    getline(cin, publisher);
    cout << "Enter developer: ";
    getline(cin, developer);

    Game newGame(name, publisher, developer);
    for (int i = 0; i < 5; ++i) {
        addAchievementToGame(newGame);
    }
    platform.addGame(newGame);
}

void addAchievementToGame(Game& game) {
    string title, description;
    int scoreValue;

    cout << "Enter achievement title: ";
    getline(cin, title);

    cout << "Enter achievement description: ";
    getline(cin, description);

    cout << "Enter achievement score value: ";
    cin >> scoreValue;
    cin.ignore();

    Achievement newAchievement(title, description, scoreValue);
    game.addAchievement(newAchievement);
}

void displayPlatforms(const std::vector<Platform>& platforms) {
    for (const auto& platform : platforms) {
        std::cout << "Platform: " << platform.getName() << ", Manufactured by: " << platform.getManufacturer() << "\n";
        for (const auto& game : platform.getGames()) {
            std::cout << "  Game: " << game.getName() << ", Published by: " << game.getPublisher() << ", Developed by: " << game.getDeveloper() << "\n";
            for (const auto& achievement : game.getAchievements()) {
                std::cout << "    Achievement: " << achievement.getTitle() << " - " << achievement.getDescription() << ", Score: " << achievement.getScoreValue() << "\n";
            }
        }
    }
}

void selectPlatform(std::vector<Platform>& platforms) {
    std::cout << "Select a platform to add a game to:\n";
    for (int i = 0; i < platforms.size(); ++i) {
        std::cout << i + 1 << ". " << platforms[i].getName() << "\n";
    }
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > platforms.size()) {
        std::cout << "Invalid selection.\n";
    }
    else {
        addGameToPlatform(platforms[choice - 1]);
    }
}

void selectGame(std::vector<Game>& games) {
    std::cout << "Select a game to add an achievement to:\n";
    for (int i = 0; i < games.size(); ++i) {
        std::cout << i + 1 << ". " << games[i].getName() << "\n";
    }
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > games.size()) {
        std::cout << "Invalid selection.\n";
    }
    else {
        addAchievementToGame(games[choice - 1]);
    }
}

