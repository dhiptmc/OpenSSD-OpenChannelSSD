
//////////////////////////////////////////////////////////////////////////////////
// nvme_identify.c for Cosmos+ OpenSSD
// Copyright (c) 2016 Hanyang University ENC Lab.
// Contributed by Yong Ho Song <yhsong@enc.hanyang.ac.kr>
//				  Youngjin Jo <yjjo@enc.hanyang.ac.kr>
//				  Sangjin Lee <sjlee@enc.hanyang.ac.kr>
//
// This file is part of Cosmos+ OpenSSD.
//
// Cosmos+ OpenSSD is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// Cosmos+ OpenSSD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Cosmos+ OpenSSD; see the file COPYING.
// If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Company: ENC Lab. <http://enc.hanyang.ac.kr>
// Engineer: Sangjin Lee <sjlee@enc.hanyang.ac.kr>
//
// Project Name: Cosmos+ OpenSSD
// Design Name: Cosmos+ Firmware
// Module Name: NVMe Identifier
// File Name: nvme_identify.c
//
// Version: v1.1.0.oc
//
// Description:
//   - generates data buffers that describes information about NVMe controller or namespace
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Revision History:
//
// * v1.1.0.oc
//   - Supports Open-Channel SSD v1.2
//
// * v1.0.1
//   - Storage size (storageCapacity_L) is determined by FTL
//
// * v1.0.0
//   - First draft
//////////////////////////////////////////////////////////////////////////////////


#include "xil_printf.h"
#include "debug.h"
#include "string.h"

#include "nvme.h"
#include "nvme_identify.h"
#include "../ftl_config.h"

void controller_identification(unsigned int pBuffer)
{
	ADMIN_IDENTIFY_CONTROLLER *identifyCNTL;
	ADMIN_IDENTIFY_POWER_STATE_DESCRIPTOR *powerStateDesc;
	
	identifyCNTL = (ADMIN_IDENTIFY_CONTROLLER*)pBuffer;

	memset(identifyCNTL, 0, sizeof(ADMIN_IDENTIFY_CONTROLLER));

	identifyCNTL->VID = PCI_VENDOR_ID;
	identifyCNTL->SSVID = PCI_SUBSYSTEM_VENDOR_ID;

	memset(identifyCNTL->SN, 0x20, 20);
	memcpy(identifyCNTL->SN, SERIAL_NUMBER, sizeof(SERIAL_NUMBER));

	memset(identifyCNTL->MN, 0x20, 40);
	memcpy(identifyCNTL->MN, MODEL_NUMBER, sizeof(MODEL_NUMBER));

	memset(identifyCNTL->FR, 0x20, 8);
	memcpy(identifyCNTL->FR, FIRMWARE_REVISION, sizeof(FIRMWARE_REVISION));


	identifyCNTL->RAB = 0x0;
	identifyCNTL->IEEE[0] = 0xE4;
	identifyCNTL->IEEE[1] = 0xD2;
	identifyCNTL->IEEE[2] = 0x5C;
	identifyCNTL->CMIC = 0x0;
	//MDTS: Maximum Data Transfer Size
	//The host should not submit a command that exceeds this transfer size
	//(2^n) * 4KB), n=8 => 1MB
	identifyCNTL->MDTS = 0x8;
	identifyCNTL->CNTLID = 0x9;

	identifyCNTL->OACS.supportsSecuritySendSecurityReceive = 0x0;
	identifyCNTL->OACS.supportsFormatNVM = 0x0;
	identifyCNTL->OACS.supportsFirmwareActivateFirmwareDownload = 0x0;

	identifyCNTL->ACL = 0x3;
	identifyCNTL->AERL = 0x3;

	identifyCNTL->FRMW.firstFirmwareSlotReadOnly = 0x1;
	identifyCNTL->FRMW.supportedNumberOfFirmwareSlots = 0x1;

	identifyCNTL->LPA.supportsSMARTHealthInformationLogPage = 0x0;

	identifyCNTL->ELPE = 0x8;
	identifyCNTL->NPSS = 0x0;
	identifyCNTL->AVSCC = 0x0;
	identifyCNTL->APSTA = 0x0;

	identifyCNTL->SQES.requiredSubmissionQueueEntrySize = 0x6;
	identifyCNTL->SQES.maximumSubmissionQueueEntrySize = 0x6;

	identifyCNTL->CQES.requiredCompletionQueueEntrySize = 0x4;
	identifyCNTL->CQES.maximumCompletionQueueEntrySize = 0x4;

	identifyCNTL->NN = 0x1;

	identifyCNTL->ONCS.supportsCompare = 0x0;
	identifyCNTL->ONCS.supportsWriteUncorrectable = 0x0;
	identifyCNTL->ONCS.supportsDataSetManagement = 0x0;

	identifyCNTL->FUSES.supportsCompareWrite = 0x0;

	identifyCNTL->FNA.formatAppliesToAllNamespaces = 0x0;
	identifyCNTL->FNA.secureEraseAppliesToAllNamespaces = 0x0;
	identifyCNTL->FNA.supportsCryptographicErase = 0x0;

	identifyCNTL->VWC.present = 0x1;

	identifyCNTL->AWUN = 0x0;
	identifyCNTL->AWUPF = 0x0;
	identifyCNTL->NVSCC = 0x0;
	identifyCNTL->ACWU = 0x0;

	identifyCNTL->SGLS.supportsSGL = 0x0;
	identifyCNTL->SGLS.supportsSGLBitBucketDescriptor = 0x0;

	powerStateDesc = &identifyCNTL->PSDx[0];

	powerStateDesc->MP = 0x09C4;
	powerStateDesc->MPS = 0x0;
	powerStateDesc->NOPS = 0x0;
	powerStateDesc->ENLAT = 0x0;
	powerStateDesc->EXLAT = 0x0;
	powerStateDesc->RRT = 0x0;
	powerStateDesc->RRL = 0x0;
	powerStateDesc->RWT = 0x0;
	powerStateDesc->RWL = 0x0;
}

void namespace_identification(unsigned int pBuffer)
{
	ADMIN_IDENTIFY_NAMESPACE *identifyNS;
	ADMIN_IDENTIFY_FORMAT_DATA *formatData;
	identifyNS = (ADMIN_IDENTIFY_NAMESPACE *)pBuffer;

	memset(identifyNS, 0, sizeof(ADMIN_IDENTIFY_NAMESPACE));

	identifyNS->NSZE[0] = storageCapacity_L;
	identifyNS->NSZE[1] = STORAGE_CAPACITY_H;
	identifyNS->NCAP[0] = storageCapacity_L;
	identifyNS->NCAP[1] = STORAGE_CAPACITY_H;
	identifyNS->NUSE[0] = storageCapacity_L;
	identifyNS->NUSE[1] = STORAGE_CAPACITY_H;

	identifyNS->NSFEAT.supportsThinProvisioning = 0x0;

	identifyNS->NLBAF = 0x0;

	identifyNS->FLBAS.supportedCombination = 0x0;
	identifyNS->FLBAS.supportsMetadataAtEndOfLBA = 0x0;

	identifyNS->MC.supportsMetadataAsPartOfLBA = 0x0;
	identifyNS->MC.supportsMetadataAsSeperate = 0x1;


	identifyNS->DPC.supportsProtectionType1 = 0x0;
	identifyNS->DPC.supportsProtectionType2 = 0x0;
	identifyNS->DPC.supportsProtectionType3 = 0x0;
	identifyNS->DPC.supportsProtectionFirst8 = 0x0;
	identifyNS->DPC.supportsProtectionLast8 = 0x0;

	identifyNS->DPS.protectionEnabled = 0x0;
	identifyNS->DPS.protectionInFirst8 = 0x0;

	identifyNS->NMIC.supportsMultipathIOSharing = 0x0;

	identifyNS->RESCAP.supportsPersistThroughPowerLoss = 0x0;
	identifyNS->RESCAP.supportsWriteExclusiveReservation = 0x0;
	identifyNS->RESCAP.supportsWriteExclusiveRegistrants = 0x0;
	identifyNS->RESCAP.supportsExclusiveAccessRegistrants = 0x0;
	identifyNS->RESCAP.supportsWriteExclusiveAllRegistrants = 0x0;
	identifyNS->RESCAP.supportsExclusiveAccessAllRegistrants = 0x0;

	formatData = &identifyNS->LBAFx[0];

	formatData->MS = NVME_METADATA_SIZE;//16-bytes
	formatData->LBADS = 0xC;
	formatData->RP = 0x2;

	identifyNS->VS[0] = 0x1;
}

void ocssd_identification(unsigned int pBuffer)
{
	ADMIN_OCSSD_IDENTIFICATION *ocssdIdentification;

	ocssdIdentification = (ADMIN_OCSSD_IDENTIFICATION *) pBuffer;

	memset(ocssdIdentification, 0, sizeof(ADMIN_OCSSD_IDENTIFICATION));

	ocssdIdentification->version = 1;
	ocssdIdentification->VNCMT = 0;
	ocssdIdentification->CGRPS = 1;

	ocssdIdentification->CAP.badBlockTableManagement = 1;
	ocssdIdentification->CAP.hybridCommandSupport = 0;

	ocssdIdentification->DOM.hybridMode = 0;
	ocssdIdentification->DOM.errorCodeCorrectionMode = 0;

	ocssdIdentification->PPAF.channelBitStart = PPA_CHANNEL_BIT_START;
	ocssdIdentification->PPAF.channelBitLength = PPA_CHANNEL_BIT_LENGTH;
	ocssdIdentification->PPAF.LUNBitStart = PPA_LUN_BIT_START;
	ocssdIdentification->PPAF.LUNBitLength = PPA_LUN_BIT_LENGTH;
	ocssdIdentification->PPAF.planeBitStart = PPA_PLANE_BIT_START;
	ocssdIdentification->PPAF.planeBitLength = PPA_PLANE_BIT_LENGTH;
	ocssdIdentification->PPAF.blockBitStart = PPA_BLOCK_BIT_START;
	ocssdIdentification->PPAF.blockBitLength = PPA_BLOCK_BIT_LENGTH;
	ocssdIdentification->PPAF.pageBitStart = PPA_PAGE_BIT_START;
	ocssdIdentification->PPAF.pageBitLength = PPA_PAGE_BIT_LENGTH;
	ocssdIdentification->PPAF.sectorBitStart = PPA_SECTOR_BIT_START;
	ocssdIdentification->PPAF.sectorBitLength = PPA_SECTOR_BIT_LENGTH;

	ocssdIdentification->groupDescription[0].MTYPE = 0;
	ocssdIdentification->groupDescription[0].FMTYPE = 0;
	ocssdIdentification->groupDescription[0].numberOfChannels = NUMBER_OF_CHANNELS_ON_DEVICE;
	ocssdIdentification->groupDescription[0].numberOfLUNs = NUMBER_OF_LUNS_PER_CHANNEL;
	ocssdIdentification->groupDescription[0].numberOfPlanes = NUMBER_OF_PLANES_PER_LUN;
	ocssdIdentification->groupDescription[0].numberOfBlocks = NUMBER_OF_BLOCKS_PER_PLANE;
	ocssdIdentification->groupDescription[0].numberOfPages = NUMBER_OF_PAGES_PER_BLOCK;
	ocssdIdentification->groupDescription[0].pageSize = PAGE_SIZE;
	ocssdIdentification->groupDescription[0].CSECS = MINIMUM_DATA_UNIT_SIZE_FOR_ECC;
	ocssdIdentification->groupDescription[0].SOS = OCSSD_METADATA_SIZE;
	ocssdIdentification->groupDescription[0].TRDT = 75000;//75us
	ocssdIdentification->groupDescription[0].TRDM = 110000;//110us
	ocssdIdentification->groupDescription[0].TPRT = 1500000;//1.5ms
	ocssdIdentification->groupDescription[0].TPRM = 5000000;//5ms
	ocssdIdentification->groupDescription[0].TBET = 5000000;//5ms
	ocssdIdentification->groupDescription[0].TBEM = 10000000;//10ms
	ocssdIdentification->groupDescription[0].MPOS.singlePlaneRead = 1;
	ocssdIdentification->groupDescription[0].MPOS.singlePlaneProgram = 1;
	ocssdIdentification->groupDescription[0].MPOS.singlePlaneErase = 1;
	ocssdIdentification->groupDescription[0].MPOS.dualPlaneRead = 1;
	ocssdIdentification->groupDescription[0].MPOS.dualPlaneProgram = 1;
	ocssdIdentification->groupDescription[0].MPOS.dualPlaneErase = 1;
	ocssdIdentification->groupDescription[0].MCCAP.SLCMode = 1;
	ocssdIdentification->groupDescription[0].MCCAP.commandSuspension = 0;
	ocssdIdentification->groupDescription[0].MCCAP.scrambleOnOff = 0;
	ocssdIdentification->groupDescription[0].MCCAP.encryption = 0;
	ocssdIdentification->groupDescription[0].CPAR = 1;
	ocssdIdentification->groupDescription[0].MTS.idCodes[0] = 0;
	ocssdIdentification->groupDescription[0].MTS.idCodes[1] = 0;
}

