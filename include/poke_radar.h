#ifndef GUARD_POKERADAR_H
#define GUARD_POKERADAR_H

#define POKE_RADAR_STEPS_TO_CHARGE 50

bool8 ChoosePokeRadarShakeCoords(s16 baseX, s16 baseY);
void BreakPokeRadarChain(void);
void IncrementPokeRadarChain(void);
void SetPokeRadarPokemon(u16 species, u8 level);
bool8 CanUsePokeRadar(u8 taskId);
void TrySetPokeRadarPatchCoords(void);
void Task_StartPokeRadarGrassShake(u8 taskId);
void ItemUseOnFieldCB_PokeRadar(u8 taskId);
void UpdatePokeRadarAfterWildBattle(u8 battleOutcome);
void InitNewPokeRadarChain(u16 species, u8 level, u8 patchType);
void ChargePokeRadar(void);

#endif
