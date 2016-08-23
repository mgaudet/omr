/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2015, 2015
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#include "cudaTests.hpp"

static const J9CudaError errors[] = {J9CUDA_NO_ERROR,
									 J9CUDA_ERROR_MISSING_CONFIGURATION,
									 J9CUDA_ERROR_MEMORY_ALLOCATION,
									 J9CUDA_ERROR_INITIALIZATION_ERROR,
									 J9CUDA_ERROR_LAUNCH_FAILURE,
									 J9CUDA_ERROR_LAUNCH_TIMEOUT,
									 J9CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
									 J9CUDA_ERROR_INVALID_DEVICE_FUNCTION,
									 J9CUDA_ERROR_INVALID_CONFIGURATION,
									 J9CUDA_ERROR_INVALID_DEVICE,
									 J9CUDA_ERROR_INVALID_VALUE,
									 J9CUDA_ERROR_INVALID_PITCH_VALUE,
									 J9CUDA_ERROR_INVALID_SYMBOL,
									 J9CUDA_ERROR_MAP_BUFFER_OBJECT_FAILED,
									 J9CUDA_ERROR_UNMAP_BUFFER_OBJECT_FAILED,
									 J9CUDA_ERROR_INVALID_HOST_POINTER,
									 J9CUDA_ERROR_INVALID_DEVICE_POINTER,
									 J9CUDA_ERROR_INVALID_TEXTURE,
									 J9CUDA_ERROR_INVALID_TEXTURE_BINDING,
									 J9CUDA_ERROR_INVALID_CHANNEL_DESCRIPTOR,
									 J9CUDA_ERROR_INVALID_MEMCPY_DIRECTION,
									 J9CUDA_ERROR_INVALID_FILTER_SETTING,
									 J9CUDA_ERROR_INVALID_NORM_SETTING,
									 J9CUDA_ERROR_CUDART_UNLOADING,
									 J9CUDA_ERROR_UNKNOWN,
									 J9CUDA_ERROR_INVALID_RESOURCE_HANDLE,
									 J9CUDA_ERROR_NOT_READY,
									 J9CUDA_ERROR_INSUFFICIENT_DRIVER,
									 J9CUDA_ERROR_SET_ON_ACTIVE_PROCESS,
									 J9CUDA_ERROR_INVALID_SURFACE,
									 J9CUDA_ERROR_NO_DEVICE,
									 J9CUDA_ERROR_ECCUNCORRECTABLE,
									 J9CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
									 J9CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
									 J9CUDA_ERROR_UNSUPPORTED_LIMIT,
									 J9CUDA_ERROR_DUPLICATE_VARIABLE_NAME,
									 J9CUDA_ERROR_DUPLICATE_TEXTURE_NAME,
									 J9CUDA_ERROR_DUPLICATE_SURFACE_NAME,
									 J9CUDA_ERROR_DEVICES_UNAVAILABLE,
									 J9CUDA_ERROR_INVALID_KERNEL_IMAGE,
									 J9CUDA_ERROR_NO_KERNEL_IMAGE_FOR_DEVICE,
									 J9CUDA_ERROR_INCOMPATIBLE_DRIVER_CONTEXT,
									 J9CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
									 J9CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
									 J9CUDA_ERROR_DEVICE_ALREADY_IN_USE,
									 J9CUDA_ERROR_PROFILER_DISABLED,
									 J9CUDA_ERROR_ASSERT,
									 J9CUDA_ERROR_TOO_MANY_PEERS,
									 J9CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED,
									 J9CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED,
									 J9CUDA_ERROR_OPERATING_SYSTEM,
									 J9CUDA_ERROR_PEER_ACCESS_UNSUPPORTED,
									 J9CUDA_ERROR_LAUNCH_MAX_DEPTH_EXCEEDED,
									 J9CUDA_ERROR_LAUNCH_FILE_SCOPED_TEX,
									 J9CUDA_ERROR_LAUNCH_FILE_SCOPED_SURF,
									 J9CUDA_ERROR_SYNC_DEPTH_EXCEEDED,
									 J9CUDA_ERROR_LAUNCH_PENDING_COUNT_EXCEEDED,
									 J9CUDA_ERROR_NOT_PERMITTED,
									 J9CUDA_ERROR_NOT_SUPPORTED,
									 J9CUDA_ERROR_STARTUP_FAILURE,
									 J9CUDA_ERROR_NOT_FOUND};

/**
 * Verify errors API.
 */
TEST_F(CudaDeviceTest, error)
{
	OMRPORT_ACCESS_FROM_OMRPORT(getPortLibrary());

	for (uint32_t index = 0; index < LENGTH_OF(errors); ++index) {
		int32_t error = errors[index];
		const char *text = omrcuda_getErrorString(error);

		ASSERT_TRUE((NULL != text) || !isErrorStringRequired(error)) << "no text for error " << error;
	}
}
