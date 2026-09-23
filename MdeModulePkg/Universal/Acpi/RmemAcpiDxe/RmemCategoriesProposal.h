/** @file
  Defines proposed RMEM main-category and subcategory values.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent

  This file is a discussion draft. The values and definitions are not
  standardized and may change based on review.

  Main categories and subcategories are serialized as UINT16 values.

  An Undivided subcategory reports a reservation only at its main-category
  level. Within one nonzero group, an Undivided entry must not coexist with
  entries using detailed subcategories.

  An AlignmentPadding subcategory describes actual physical address space made
  unavailable solely by allocation alignment or hardware-decoder granularity.
  It must have a nonzero size and should use the same group identifier as the
  allocation that caused it.
**/

#ifndef RMEM_CATEGORIES_PROPOSAL_H_
#define RMEM_CATEGORIES_PROPOSAL_H_

///
/// Identifies the high-level purpose or owner of a reserved-memory range.
///
typedef enum {
  ///
  /// Invalid or uninitialized category.
  ///
  RmemCategoryUnknown               = 0,

  ///
  /// Memory reserved for security services, protected execution, security
  /// processors, or system-management environments.
  ///
  RmemCategorySecurity              = 1,

  ///
  /// Memory intentionally shared by multiple processors, devices, IP blocks,
  /// firmware environments, or operating-system components.
  ///
  RmemCategorySharedMemory          = 2,

  ///
  /// Memory reserved specifically for display-framebuffer use.
  ///
  RmemCategoryDisplayFramebuffer    = 3,

  ///
  /// Memory reserved primarily for GPU operation.
  ///
  RmemCategoryGpuReserved           = 4,

  ///
  /// Memory reserved primarily for a dedicated AI or machine-learning
  /// accelerator.
  ///
  RmemCategoryAiAcceleratorReserved = 5,

  ///
  /// Memory reserved for platform firmware, silicon initialization, ACPI,
  /// runtime services, logging, or firmware diagnostics.
  ///
  RmemCategoryFirmware              = 6,

  ///
  /// A reservation that does not fit another main category.
  ///
  RmemCategoryOther                 = 7,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemCategoryMax                   = 8
} RMEM_CATEGORY;

///
/// Security subcategories.
///
typedef enum {
  ///
  /// Reports the security reservation without finer subdivision.
  ///
  RmemSecuritySubCategoryUndivided         = 0,

  ///
  /// Memory protected from normal software or device access.
  ///
  RmemSecuritySubCategoryProtectedMemory   = 1,

  ///
  /// Memory owned by or assigned to a security processor.
  ///
  RmemSecuritySubCategorySecurityProcessor = 2,

  ///
  /// Memory used for an isolated or trusted execution environment.
  ///
  RmemSecuritySubCategoryIsolatedExecution = 3,

  ///
  /// Memory used by system-management firmware, such as SMM or an
  /// architecture-equivalent execution environment.
  ///
  RmemSecuritySubCategorySystemManagement  = 4,

  ///
  /// Memory reserved for keys, measurements, or other security state.
  ///
  RmemSecuritySubCategoryKeyStorage        = 5,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for a security reservation.
  ///
  RmemSecuritySubCategoryAlignmentPadding  = 6,

  ///
  /// A distinct security reservation with no matching standard subcategory.
  ///
  RmemSecuritySubCategoryOther             = 7,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemSecuritySubCategoryMax               = 8
} RMEM_SECURITY_SUBCATEGORY;

///
/// Shared-memory subcategories.
///
typedef enum {
  ///
  /// Reports the shared-memory reservation without finer subdivision.
  ///
  RmemSharedMemorySubCategoryUndivided                = 0,

  ///
  /// Memory used for communication between firmware components or firmware
  /// execution phases.
  ///
  RmemSharedMemorySubCategoryFirmwareCommunication    = 1,

  ///
  /// Memory shared between secure and nonsecure execution environments.
  ///
  RmemSharedMemorySubCategorySecureWorldCommunication = 2,

  ///
  /// Memory shared between a host processor and one or more devices.
  ///
  RmemSharedMemorySubCategoryHostDevice               = 3,

  ///
  /// Memory shared directly between devices or IP blocks.
  ///
  RmemSharedMemorySubCategoryDeviceToDevice           = 4,

  ///
  /// Memory shared by multiple compute accelerators, such as a GPU and an AI
  /// accelerator.
  ///
  RmemSharedMemorySubCategoryAcceleratorShared        = 5,

  ///
  /// Memory containing shared command, work, or completion queues.
  ///
  RmemSharedMemorySubCategoryCommandQueue             = 6,

  ///
  /// Memory used as a shared mailbox.
  ///
  RmemSharedMemorySubCategoryMailbox                  = 7,

  ///
  /// Memory containing shared synchronization, signaling, or coordination
  /// state.
  ///
  RmemSharedMemorySubCategorySynchronization          = 8,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for a shared-memory reservation.
  ///
  RmemSharedMemorySubCategoryAlignmentPadding         = 9,

  ///
  /// A distinct shared-memory reservation with no matching standard
  /// subcategory.
  ///
  RmemSharedMemorySubCategoryOther                    = 10,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemSharedMemorySubCategoryMax                      = 11
} RMEM_SHARED_MEMORY_SUBCATEGORY;

///
/// Display-framebuffer subcategories.
///
typedef enum {
  ///
  /// Reports the display-framebuffer reservation without finer subdivision.
  ///
  RmemDisplaySubCategoryUndivided             = 0,

  ///
  /// Framebuffer used for a pre-OS console or boot graphics.
  ///
  RmemDisplaySubCategoryPreOsFramebuffer      = 1,

  ///
  /// Framebuffer retained after operating-system boot.
  ///
  RmemDisplaySubCategoryPersistentFramebuffer = 2,

  ///
  /// Buffer directly scanned out by a display controller.
  ///
  RmemDisplaySubCategoryScanoutBuffer         = 3,

  ///
  /// Metadata associated with a framebuffer or display surface.
  ///
  RmemDisplaySubCategoryFramebufferMetadata   = 4,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for a display reservation.
  ///
  RmemDisplaySubCategoryAlignmentPadding      = 5,

  ///
  /// A distinct display reservation with no matching standard subcategory.
  ///
  RmemDisplaySubCategoryOther                 = 6,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemDisplaySubCategoryMax                   = 7
} RMEM_DISPLAY_SUBCATEGORY;

///
/// GPU subcategories.
///
typedef enum {
  ///
  /// Reports the GPU reservation without finer subdivision.
  ///
  RmemGpuSubCategoryUndivided          = 0,

  ///
  /// General memory reserved for GPU use, including stolen or preallocated
  /// device memory.
  ///
  RmemGpuSubCategoryDeviceMemory       = 1,

  ///
  /// Memory containing GPU-accessible framebuffer or display surfaces.
  ///
  RmemGpuSubCategoryFramebuffer        = 2,

  ///
  /// GPU address-translation tables or related translation structures.
  ///
  RmemGpuSubCategoryTranslationTable   = 3,

  ///
  /// Metadata used to manage compressed graphics memory.
  ///
  RmemGpuSubCategoryCompressionMetadata = 4,

  ///
  /// GPU firmware code or data.
  ///
  RmemGpuSubCategoryFirmware           = 5,

  ///
  /// GPU commands, queues, rings, or scheduling structures.
  ///
  RmemGpuSubCategoryCommandBuffer      = 6,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for a GPU reservation.
  ///
  RmemGpuSubCategoryAlignmentPadding   = 7,

  ///
  /// A distinct GPU reservation with no matching standard subcategory.
  ///
  RmemGpuSubCategoryOther              = 8,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemGpuSubCategoryMax                = 9
} RMEM_GPU_SUBCATEGORY;

///
/// AI-accelerator subcategories.
///
typedef enum {
  ///
  /// Reports the AI-accelerator reservation without finer subdivision.
  ///
  RmemAiAcceleratorSubCategoryUndivided        = 0,

  ///
  /// General working memory reserved for AI-accelerator use.
  ///
  RmemAiAcceleratorSubCategoryDeviceMemory     = 1,

  ///
  /// AI-accelerator address-translation tables or related translation
  /// structures.
  ///
  RmemAiAcceleratorSubCategoryTranslationTable = 2,

  ///
  /// AI-accelerator firmware code or data.
  ///
  RmemAiAcceleratorSubCategoryFirmware         = 3,

  ///
  /// Commands, queues, rings, or scheduling structures used by an AI
  /// accelerator.
  ///
  RmemAiAcceleratorSubCategoryCommandBuffer    = 4,

  ///
  /// Memory reserved for machine-learning models, weights, or constants.
  ///
  RmemAiAcceleratorSubCategoryModelStorage     = 5,

  ///
  /// Temporary working memory used while executing AI workloads.
  ///
  RmemAiAcceleratorSubCategoryScratchMemory    = 6,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for an AI-accelerator reservation.
  ///
  RmemAiAcceleratorSubCategoryAlignmentPadding = 7,

  ///
  /// A distinct AI-accelerator reservation with no matching standard
  /// subcategory.
  ///
  RmemAiAcceleratorSubCategoryOther            = 8,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemAiAcceleratorSubCategoryMax              = 9
} RMEM_AI_ACCELERATOR_SUBCATEGORY;

///
/// Firmware subcategories.
///
typedef enum {
  ///
  /// Reports the firmware reservation without finer subdivision.
  ///
  RmemFirmwareSubCategoryUndivided             = 0,

  ///
  /// General platform or BIOS firmware reservation.
  ///
  RmemFirmwareSubCategoryPlatformFirmware      = 1,

  ///
  /// Memory reserved by silicon-initialization firmware.
  ///
  RmemFirmwareSubCategorySiliconInitialization = 2,

  ///
  /// ACPI nonvolatile storage.
  ///
  RmemFirmwareSubCategoryAcpiNvs               = 3,

  ///
  /// Memory containing ACPI data that the operating system may reclaim.
  ///
  RmemFirmwareSubCategoryAcpiReclaimable       = 4,

  ///
  /// UEFI runtime-service executable code.
  ///
  RmemFirmwareSubCategoryRuntimeCode            = 5,

  ///
  /// UEFI runtime-service data.
  ///
  RmemFirmwareSubCategoryRuntimeData            = 6,

  ///
  /// Memory used to preserve state or execute firmware during S3 resume.
  ///
  RmemFirmwareSubCategoryS3Resume               = 7,

  ///
  /// Firmware-owned communication buffer. A buffer intentionally shared
  /// across ownership domains should use RmemCategorySharedMemory.
  ///
  RmemFirmwareSubCategoryCommunicationBuffer    = 8,

  ///
  /// Persistent firmware diagnostic, telemetry, or event log.
  ///
  RmemFirmwareSubCategoryPersistentLog          = 9,

  ///
  /// Memory reserved for crash capture, offline dump, or recovery
  /// diagnostics.
  ///
  RmemFirmwareSubCategoryCrashDiagnostics       = 10,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity for a firmware reservation.
  ///
  RmemFirmwareSubCategoryAlignmentPadding       = 11,

  ///
  /// A distinct firmware reservation with no matching standard subcategory.
  ///
  RmemFirmwareSubCategoryOther                  = 12,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemFirmwareSubCategoryMax                    = 13
} RMEM_FIRMWARE_SUBCATEGORY;

///
/// Other subcategories.
///
typedef enum {
  ///
  /// Reports the reservation without finer subdivision.
  ///
  RmemOtherSubCategoryUndivided        = 0,

  ///
  /// Platform-owned memory that does not fit another category.
  ///
  RmemOtherSubCategoryPlatformReserved = 1,

  ///
  /// Device-owned memory that does not fit another category.
  ///
  RmemOtherSubCategoryDeviceReserved   = 2,

  ///
  /// Memory retained for compatibility with legacy hardware or software.
  ///
  RmemOtherSubCategoryCompatibility    = 3,

  ///
  /// Address space unavailable because of alignment or hardware-decoder
  /// granularity.
  ///
  RmemOtherSubCategoryAlignmentPadding = 4,

  ///
  /// A distinct reservation with no matching standard classification.
  ///
  RmemOtherSubCategoryUnclassified     = 5,

  ///
  /// Exclusive upper bound. Not a valid wire value.
  ///
  RmemOtherSubCategoryMax              = 6
} RMEM_OTHER_SUBCATEGORY;

#endif