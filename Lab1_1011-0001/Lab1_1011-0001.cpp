#include <iostream>
#include <string>
using namespace std;
struct Achievement
{
    string Title;
    string Description;
    int ScoreValue;
};
struct Game
{
    string Name;
    string Publisher;
    string Developer;
    Achievement* Achievements;
};
struct Platform
{

    string Name;
    string Manufacturer;
    Game* Games;
};

int main()
{
  Platform* platforms;
  
}
void ShowAll()
{
    
}

Platform CreateNewPlatform()
{

}


Platform Initialize()
{
    Platform platform;
    platform.Name = "GoodGames";
    platform.Manufacturer = "Evil megacorp";
    platform.Games = new Game[5];

    Achievement cyberNexusAchievements[5] = {
        InitializeAchievement("Neon Warrior", "Complete the first chapter.", 300),
        InitializeAchievement("Hack Master", "Hack into 50 different systems.", 3500),
        InitializeAchievement("Shadow Operative", "Complete a mission without being detected.", 2200),
        InitializeAchievement("Rebel Leader", "Rally the resistance", 666),
        InitializeAchievement("Cybernetic Savior", "Defeat the final boss.", 10000)
    };

    Achievement lostKingdomsAchievements[5] = {
        InitializeAchievement("First Light", "Discover the lost city of Eloria.", 500),
        InitializeAchievement("Ancient Scholar", "Collect 100 ancient scrolls.", 1000),
        InitializeAchievement("Dragon Tamer", "Befriend a legendary dragon.", 1500),
        InitializeAchievement("Crown Restorer", "Reclaim the lost crown of Eloria.", 2000),
        InitializeAchievement("Master of Elements", "Master all magical elements.", 2500)
    };


    Achievement galacticOdysseyAchievements[5] = {
        InitializeAchievement("Star Explorer", "Visit 10 different planets.", 300),
        InitializeAchievement("Alien Diplomat", "Establish peace with an alien race.", 600),
        InitializeAchievement("Void Voyager", "Survive a black hole encounter.", 900),
        InitializeAchievement("Galactic Hero", "Save a planet from destruction.", 1200),
        InitializeAchievement("Universe Discoverer", "Chart an unexplored galaxy.", 1500)
    };


    Achievement timeRiftAchievements[5] = {
        InitializeAchievement("Temporal Initiate", "Complete your first time jump.", 350),
        InitializeAchievement("Paradox Solver", "Resolve a time paradox.", 700),
        InitializeAchievement("Era Explorer", "Visit five different historical periods.", 1050),
        InitializeAchievement("Guardian of Time", "Thwart a time manipulation attempt.", 1400),
        InitializeAchievement("Chrono Master", "Master all time travel mechanics.", 1750)
    };


    Achievement urbanLegendsAchievements[5] = {
        InitializeAchievement("Ghoul Hunter", "Defeat your first supernatural entity.", 400),
        InitializeAchievement("Myth Buster", "Disprove a false legend.", 800),
        InitializeAchievement("Occult Scholar", "Collect 50 artifacts of lore.", 1200),
        InitializeAchievement("Shadow Operative", "Solve a high-profile paranormal case.", 1600),
        InitializeAchievement("Legend Master", "Discover the truth behind the ultimate urban legend.", 2000)
    };


    platform.Games[0] = InitializeGame("Cyber Nexus", "Nova Interactive", "Quantum Studios", cyberNexusAchievements);
    platform.Games[1] = InitializeGame("Lost Kingdoms of Eloria", "Mythos Games", "Elder Realms", lostKingdomsAchievements);
    platform.Games[2] = InitializeGame("Galactic Odyssey", "Starbound Entertainment", "Nebula Creations", galacticOdysseyAchievements);
    platform.Games[3] = InitializeGame("Time Rift", "Epoch Entertainment", "ChronoCraft Studios", timeRiftAchievements);
    platform.Games[4] = InitializeGame("Urban Legends", "Dark City Games", "Shadow Interactive", urbanLegendsAchievements);

    return platform;
}

Platform InitializePlatform(string name, string manufacturer, Game* games)
{
    Platform platform;
    platform.Name = name;
    platform.Manufacturer = manufacturer;
    platform.Games = games;
    return platform;
}

Game InitializeGame(string name, string publisher, string developer, Achievement* achivements)
{
    Game game;
    game.Name = name;
    game.Publisher = publisher;
    game.Developer = developer;
    game.Achievements = achivements;
    return game;
}
Achievement InitializeAchievement(string title, string description, int scoreVal)
{
    Achievement achivement;
    achivement.Title = title;
    achivement.Description = description;
    achivement.ScoreValue = scoreVal;
    return achivement;
}
