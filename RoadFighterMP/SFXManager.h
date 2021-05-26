#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

class SFXManager
{
public:
	static SFXManager* getInstance();
	void testFunction();

	void loadAll();
	sf::Sound* getSFX(std::string);
private:
	// set constructor to private
	SFXManager() {};
	// set copy contructor to private
	SFXManager(SFXManager const&) {};
	// assignment operator is private
	SFXManager& operator=(SFXManager const&) {};
	static SFXManager* sharedInstance;

	void loadSFX(std::string, std::string);
	std::unordered_map<std::string, sf::Sound*> sfxMap;
};