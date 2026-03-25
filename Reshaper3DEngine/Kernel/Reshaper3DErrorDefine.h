#pragma once

enum RsErrorCode
{
	RsErrorCode_BaseNumber						= -99999 ,
	RsErrorCode_File							= RsErrorCode_BaseNumber + 100,		// -99899
	RsErrorCode_File_DoesNotExist				,
	RsErrorCode_File_NameIsEmpty				,
	RsErrorCode_File_FailToMakeHyJob			,
	RsErrorCode_File_FolderDoesNotExist			,
	RsErrorCode_Object							= RsErrorCode_BaseNumber + 200 ,	// -99799
	RsErrorCode_Object_BuildProcessIsNull		,
	RsErrorCode_Object_HatchAngleIsInvalid		,
	RsErrorCode_Object_Function					= RsErrorCode_BaseNumber + 300 ,	// -99699
	RsErrorCode_Object_Function_NotSatisfied	,
	RsErrorCode_Object_Function_NotOnlyVectors	,
	RsErrorCode_Etc								= RsErrorCode_BaseNumber + 90000 ,	// -09699
	RsErrorCode_Success							= 0	,								// 0
};