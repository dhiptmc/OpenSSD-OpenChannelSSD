//////////////////////////////////////////////////////////////////////////////////
// request_transform.h for Cosmos+ OpenSSD
// Copyright (c) 2017 Hanyang University ENC Lab.
// Contributed by Yong Ho Song <yhsong@enc.hanyang.ac.kr>
//				  Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
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
// Engineer: Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
//
// Project Name: Cosmos+ OpenSSD
// Design Name: Cosmos+ Firmware
// Module Name: Request Scheduler
// File Name: request_transform.h
//
// Version: v1.0.0
//
// Description:
//   - define parameters, data structure and functions of request scheduler
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Revision History:
//
// * v1.0.0
//   - First draft
//////////////////////////////////////////////////////////////////////////////////

#ifndef REQUEST_TRANSFORM_H_
#define REQUEST_TRANSFORM_H_

#include "ftl_config.h"
#include "nvme/nvme.h"

#define NVME_COMMAND_AUTO_COMPLETION_OFF	0
#define NVME_COMMAND_AUTO_COMPLETION_ON		1

#define BUF_DEPENDENCY_REPORT_BLOCKED		0
#define BUF_DEPENDENCY_REPORT_PASS			1

void ReqTransNvmeToSlice(unsigned int cmdSlotTag, unsigned int startLba, unsigned int nlb, unsigned int cmdCode, unsigned int w_ptr);
void ReqTransSliceToLowLevel();
void IssueNvmeDmaReq(unsigned int reqSlotTag);
void CheckDoneNvmeDmaReq();

void SelectLowLevelReqQ(unsigned int reqSlotTag);
void ReleaseBlockedByBufDepReq(unsigned int reqSlotTag);

#endif /* REQUEST_TRANSFORM_H_ */
