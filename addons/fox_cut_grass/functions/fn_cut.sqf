_player = _this select 0;
_classClutter = _this select 1;
_duration = _this select 2;

if (!isTouchingGround _player) exitWith {hint format["You cannot cut grass here!"]; };

_dummy = "Land_HelipadEmpty_F" createVehicle getpos _player;
[(_dummy),"fox_cut_grass_sound"]remoteExec ["say3D"];
player playAction "PlayerProne";
[_duration, [_player,_dummy,_classClutter], {

  _args = _this select 0;
  _player = _args select 0;
  _dummy = _args select 1;
  _classClutter = _args select 2;

  _clutter = _classClutter createVehicle getpos _player;
  _clutter setpos(getpos _player);
  deleteVehicle _dummy;

}, {

  _args = _this select 0;
  _player = _args select 0;
  _dummy = _args select 1;
  _classClutter = _args select 2;

  deleteVehicle _dummy;

}, "..."] call ace_common_fnc_progressBar
