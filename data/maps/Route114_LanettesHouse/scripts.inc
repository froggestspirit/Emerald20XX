Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	goto_if_set FLAG_RECEIVED_EEVEE_LANETTE, Route114_LanettesHouse_EventScript_LanettePostEevee
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 15, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Route114_LanettesHouse_EventScript_ReceiveEeveeParty
	compare VAR_RESULT, 1
	goto_if_eq Route114_LanettesHouse_EventScript_ReceiveEeveePC
	goto Common_EventScript_NoMoreRoomForPokemon
Route114_LanettesHouse_EventScript_LanettePostEevee::
	setflag FLAG_RECEIVED_EEVEE_LANETTE
	givedecoration DECOR_LOTAD_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_ReceiveEeveeParty::
	call Route114_LanettesHouse_EventScript_ReceivedEeveeFanfare
	goto_if_set FLAG_NUZLOCKE_ACTIVE, Nuzlocke_Name_RecievedEevee
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route114_LanettesHouse_EventScript_LanettePostEevee
Nuzlocke_Name_RecievedEevee::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route114_LanettesHouse_EventScript_LanettePostEevee

Route114_LanettesHouse_EventScript_ReceiveEeveePC::
	call Route114_LanettesHouse_EventScript_ReceivedEeveeFanfare
	goto_if_set FLAG_NUZLOCKE_ACTIVE, Nuzlocke_Name_RecievedEeveePC
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route114_LanettesHouse_EventScript_SendEeveeToPC
Nuzlocke_Name_RecievedEeveePC::
	call Common_EventScript_NameReceivedBoxMon
	goto Route114_LanettesHouse_EventScript_SendEeveeToPC

Route114_LanettesHouse_EventScript_SendEeveeToPC::
	call Common_EventScript_TransferredToPC
	goto Route114_LanettesHouse_EventScript_LanettePostEevee

Route114_LanettesHouse_EventScript_ReceivedEeveeFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route114_LanettesHouse_Text_PlayerReceivedEevee
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_EEVEE
	return

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

Route114_LanettesHouse_Text_PlayerReceivedEevee:
	.string "{PLAYER} received EEVEE!$"
