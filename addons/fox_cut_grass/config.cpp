#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		units[] = {};
		weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_main"};
	};
};

class CfgFunctions
{
	class ADDON
	{
		class COMPONENT
		{
			file="\fox_cut_grass\functions";
			class cut{};
		};
	};
};

class CfgSounds
{
	sounds[] = {fox_cut_grass_sound};
	class fox_cut_grass_sound
	{
		name = "fox_cut_grass_sound";
		sound[] = {"\fox_cut_grass\sounds\cut_grass.ogg", 7, 1};
		titles[] = {};
	};
};

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {

					class fox_environment{
						displayName = "Grass";
						condition = "player == vehicle player";
						exceptions[] = {"isNotInside", "isNotSitting", "isNotOnLadder"};
						statement = "";

						class fox_cut_grass_small {
								displayName = "Cut small area";
								condition = "alive player";
								exceptions[] = {"isNotInside", "isNotSwimming", "isNotSitting"};
								statement = "[_player,'Land_ClutterCutter_small_F',5] call fox_cut_grass_fnc_cut";
								icon = "\fox_cut_grass\ui\cut.paa";
						};
						class fox_cut_grass_medium {
								displayName = "Cut medium area";
								condition = "alive player";
								exceptions[] = {"isNotInside", "isNotSwimming", "isNotSitting"};
								statement = "[_player,'Land_ClutterCutter_medium_F',15] call fox_cut_grass_fnc_cut";
								icon = "\fox_cut_grass\ui\cut.paa";
						};

					};
				};
		};
};
