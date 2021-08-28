#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "strings.h"
#include "util.h"
#include "constants/songs.h"

struct Unk81D5014
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 *unk10;
};

struct Unk03006370
{
    u16 unk0;
    u32 unk4;
    u32 *unk8;
};

static void sub_81D5084(u8);

struct Unk03006370 gUnknown_03006370;

extern const u8 gUnknown_089A3470[];

static void sub_81D4D50(struct Unk03006370 *arg0, int arg1, u32 *arg2)
{

}

static void sub_81D4DB8(struct Unk03006370 *arg0)
{

}

static u8 sub_81D4DE8(struct Unk03006370 *arg0)
{

}

static void OpenEReaderLink(void)
{

}

static bool32 sub_81D4E60(void)
{

}

static bool32 sub_81D4EC0(void)
{

}

static u32 sub_81D4EE4(u8 *arg0, u16 *arg1)
{

}

void task_add_00_ereader(void)
{
    struct Unk81D5014 *data;
    u8 taskId = CreateTask(sub_81D5084, 0);
    data = (struct Unk81D5014 *)gTasks[taskId].data;
    data->unk8 = 0;
    data->unk9 = 0;
    data->unkA = 0;
    data->unkB = 0;
    data->unkC = 0;
    data->unkD = 0;
    data->unk0 = 0;
    data->unk2 = 0;
    data->unk4 = 0;
    data->unk6 = 0;
    data->unkE = 0;
    data->unk10 = AllocZeroed(0x40);
}

static void sub_81D505C(u16 *arg0)
{
    *arg0 = 0;
}

static bool32 sub_81D5064(u16 *arg0, u16 arg1)
{

}

static void sub_81D5084(u8 taskId)
{
    
}
