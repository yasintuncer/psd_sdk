// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once


PSD_NAMESPACE_BEGIN

/// \ingroup Types
/// \class Channel
/// \brief A struct representing a channel as stored in the layers of the Layer Mask section.
/// \sa Layer
struct Channel
{
	uint64_t fileOffset;				///< The offset from the start of the file where the channel's data is stored.
	uint32_t size;						///< The size of the channel data to be read from the file.
	void* data;							///< Planar data the size of the layer the channel belongs to. Data is only valid if the type member indicates so.
	int16_t type;						///< One of the \ref channelType constants denoting the type of data.

	//NOTE: The following members are not part of the psd sdk.  It is used to export channel elements under a structure.
	//		They are not written to  the psd file. added by @yasintuncer
	unsigned int bytesPerPixel;				///< The number of bytes per pixel for the channel data.
	unsigned int width;							///< The width of the channel data.
	unsigned int height;						///< The height of the channel data.
	uint16_t opacity;					///< The opacity of the channel.
	uint16_t color[4];					///< The color of the channel.
	uint8_t colorspace;					///< The colorspace of the channel.
	uint8_t mode;						///< The blend mode of the channel.	
};

PSD_NAMESPACE_END
