#ifndef _VKTPIPELINEMAKEUTIL_HPP
#define _VKTPIPELINEMAKEUTIL_HPP
/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2016 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Object creation utilities
 *//*--------------------------------------------------------------------*/

#include "vkDefs.hpp"
#include "vkRef.hpp"
#include "vkMemUtil.hpp"
#include "deUniquePtr.hpp"
#include "tcuVector.hpp"

namespace vkt
{
namespace pipeline
{

class Buffer
{
public:
										Buffer			(const vk::DeviceInterface&		vk,
														 const vk::VkDevice				device,
														 vk::Allocator&					allocator,
														 const vk::VkBufferCreateInfo&	bufferCreateInfo,
														 const vk::MemoryRequirement	memoryRequirement);

	const vk::VkBuffer&					get				(void) const { return *m_buffer; }
	const vk::VkBuffer&					operator*		(void) const { return get(); }
	vk::Allocation&						getAllocation	(void) const { return *m_allocation; }

private:
	const vk::Unique<vk::VkBuffer>		m_buffer;
	const de::UniquePtr<vk::Allocation>	m_allocation;

										Buffer			(const Buffer&);	// "deleted"
	Buffer&								operator=		(const Buffer&);
};

class Image
{
public:
										Image			(const vk::DeviceInterface&		vk,
														 const vk::VkDevice				device,
														 vk::Allocator&					allocator,
														 const vk::VkImageCreateInfo&	imageCreateInfo,
														 const vk::MemoryRequirement	memoryRequirement);

	const vk::VkImage&					get				(void) const { return *m_image; }
	const vk::VkImage&					operator*		(void) const { return get(); }
	vk::Allocation&						getAllocation	(void) const { return *m_allocation; }

private:
	const vk::Unique<vk::VkImage>		m_image;
	const de::UniquePtr<vk::Allocation>	m_allocation;

										Image			(const Image&);		// "deleted"
	Image&								operator=		(const Image&);
};

vk::Move<vk::VkCommandBuffer>	makeCommandBuffer		(const vk::DeviceInterface& vk, const vk::VkDevice device, const vk::VkCommandPool commandPool);
vk::Move<vk::VkPipeline>		makeComputePipeline		(const vk::DeviceInterface& vk, const vk::VkDevice device, const vk::VkPipelineLayout pipelineLayout, const vk::VkShaderModule shaderModule, const vk::VkSpecializationInfo* specInfo);
de::MovePtr<vk::Allocation>		bindImageDedicated		(const vk::InstanceInterface& vki, const vk::DeviceInterface& vkd, const vk::VkPhysicalDevice physDevice, const vk::VkDevice device, const vk::VkImage image, const vk::MemoryRequirement requirement);
de::MovePtr<vk::Allocation>		bindBufferDedicated		(const vk::InstanceInterface& vki, const vk::DeviceInterface& vkd, const vk::VkPhysicalDevice physDevice, const vk::VkDevice device, const vk::VkBuffer buffer, const vk::MemoryRequirement requirement);

} // pipeline
} // vkt

#endif // _VKTPIPELINEMAKEUTIL_HPP
