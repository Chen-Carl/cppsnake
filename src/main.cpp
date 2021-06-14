#include "Game.h"
#include "zclog.h"

using namespace cppsnake;

int main()
{
	YAML::Node root = YAML::LoadFile("/home/zoecarl/snake/log.yml");
	zcserver::Config::LoadFromYaml(root);

	Game game;
	game.run();

	return 0;
}