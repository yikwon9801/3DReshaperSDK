#pragma once

typedef enum : BYTE // 1byte
{
	HY_DATA_TYPE_DLP_SLA	= 1,
	HY_DATA_TYPE_SLA		= 2,
}HyDataType;

typedef enum : BYTE	// 1byte
{
	R_1920x1080_1BPP_INDEXED_COMPRESSED = 1
}HyDLP_Info;

typedef enum : UINT16 // 2byte
{
	HY_TAG_NONE = 0x00,
	HY_TAG_START = 0xE000,													// empty
	HY_TAG_END = 0xE001,													// empty
	
#pragma region Header
	HY_TAG_HEADER_START = 0x1000,											// empty

	HY_TAG_HOST_VERSION = 0x1001,                                           // string(n)
	HY_TAG_SLICER_VERSION = 0x1002,                                         // string(n)
	HY_TAG_RENDERING_VERSION = 0x1003,                                         // string(n)
	HY_TAG_ENGINE_VERSION = 0x1004,                                         // string(n)
	HY_TAG_SOURCE_REVISION = 0x1005,									    // string(n)
	HY_TAG_PLATFORM	= 0x1006,												// BoundingBox(8 * 6)
	HY_TAG_CREATION_TIMESTAMP = 0x1010,                                     // int(4)
	HY_TAG_DATA_TYPE = 0x1020,                                              // HyDataType(1)
	HY_TAG_SECURITY_KEY = 0x1030,                                           // string(n)
	HY_TAG_DEVICE_TYPE = 0x1040,                                            // TODO: not defined, yet
	HY_TAG_METERIAL_TYPE = 0x1041,                                          // TODO: not defined, yet
	HY_TAG_MODEL_NAME = 0x1042,                                             // string(n): seperate by ;
	HY_TAG_LAYER_COUNT = 0x1043,                                            // int(4)
	HY_TAG_PATH_COUNT = 0x1044,                                             // int(4)
	HY_TAG_SLICE_DIMENSION = 0x1045,                                        // BoundingBox(4 * 6)
	HY_TAG_LAYER_COUNTTOSKIPRECOAT = 0x1046,                                // int(4)
	HY_TAG_SCANFIELD = 0x1047,												// empty
	HY_TAG_DATA_COMPRESS = 0x1050,                                          // bool(1)
	HY_TAG_SKIP_RECOATER_NUMBER = 0x1051,                                          // bool(1)
	HY_TAG_ESTIMATE_PRINT_TIME = 0x1052,                                    // int(4)
	HY_TAG_ESTIMATE_METERIAL = 0x1053,                                      // int(4)
	HY_TAG_THUMB_START = 0x1060,											// empty
	HY_TAG_THUMB_IMAGE_WIDTH = 0x1061,											// empty
	HY_TAG_THUMB_IMAGE_HEIGHT = 0x1062,											// empty
	HY_TAG_THUMB_IMAGE_FORMAT = 0x1063,											// empty
	HY_TAG_THUMB_IMAGE_SIZE = 0x1064,											// empty
	HY_TAG_THUMB_IMAGE_BUFF = 0x1065,											// empty
	HY_TAG_THUMB_END = 0x106F,											// empty

	HY_TAG_POSITION_OPTION_SETTING = 0x1071,
	HY_TAG_POSITION_OPTION_DEVICE = 0x1072,
	HY_TAG_POSITION_OPTION_METERIAL = 0x1073,
	HY_TAG_POSITION_OPTION_SLICE = 0x1074,
	HY_TAG_POSITION_TABLE_SLICE_DATA = 0x1075,
	HY_TAG_POSITION_TABLE_GROUP_DATA = 0x1076,

	HY_TAG_RECOATER_STARTSIDE = 0x1090,
	HY_TAG_RECOATER_CYCLE = 0x1091,
	HY_TAG_GASFLOW_ANGLE = 0x1092,
	HY_TAG_PRINT_TYPE = 0x1093,

	HY_TAG_HEADER_END = 0x10F0,												// empty

	// slice data
	HY_TAG_DATA_START = 0x3010,
	HY_TAG_DATA_LAYER_INDEX = 0x3011,
	HY_TAG_SLA_MINMAX = 0x3012,
	HY_TAG_SLA_LASERINFO = 0x3013,
	HY_TAG_SLA_DATA = 0x3014,
	HY_TAG_SLA_GALVANOINFO = 0x3015,
	HY_TAG_SLA_SKYWRITINGINFO = 0x3016,
	HY_TAG_DLP_DATA_INFO = 0x3020,
	HY_TAG_DLP_DATA1 = 0x3021,
	HY_TAG_DLP_DATA2 = 0x3022,
	HY_TAG_DATA_LAYER_END = 0x3030,
	HY_TAG_DATA_END = 0x30F0,

	HY_TAG_SLICEMETA_DATA_START = 0x3100,
	HY_TAG_SLICEMETA_DATA_END = 0x3101,
	HY_TAG_SLICEMETA_DATA_LASER_PROPERTY = 0x3102,
	HY_TAG_SLICEMETA_DATA_HEIGHT = 0x3103,
	HY_TAG_SLICEMETA_DATA_BINTABLE = 0x3104,
	HY_TAG_SLICEMETA_DATA_STARTINGPOSITIONINFILE = 0x3105,
	HY_TAG_SLICEMETA_DATA_BOUNDINGBOXFORSLICE = 0x3106,
	HY_TAG_SLICEMETA_DATA_PART_PROPERTY = 0x3107,

	// image data
	HY_TAG_IMAGE_DATA_START = 0x5010,

	HY_TAG_IMAGE_DATA_END = 0x50F0,

	// each table info
	HY_TAG_GROUP_INFO_TABLE = 0x7011,
	HY_TAG_GROUP_SIZE = 0x7012,
	HY_TAG_LASERPROPERTIES_TABLE = 0x7013,
	HY_TAG_LASERPROPERTIES_SIZE = 0x7014,
	HY_TAG_GALVANODELAYPROPERTIES_TABLE = 0x7015,
	HY_TAG_GALVANODELAYPROPERTIES_SIZE = 0x7016,
	HY_TAG_SKYWRITINGPROPERTIES_TABLE = 0x7017,
	HY_TAG_SKYWRITINGPROPERTIES_SIZE = 0x7018,
	HY_TAG_SLICE_DATA_TABLE = 0x7021,
	

	// laser properties info
	
	// galvano meter properties info


#pragma endregion


}HyDataTagType;
