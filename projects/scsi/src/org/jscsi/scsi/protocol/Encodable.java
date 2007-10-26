//
// Cleversafe open-source code header - Version 1.1 - December 1, 2006
//
// Cleversafe Dispersed Storage(TM) is software for secure, private and
// reliable storage of the world's data using information dispersal.
//
// Copyright (C) 2005-2007 Cleversafe, Inc.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
// USA.
//
// Contact Information: Cleversafe, 10 W. 35th Street, 16th Floor #84,
// Chicago IL 60616
// email licensing@cleversafe.org
//
// END-OF-HEADER
//-----------------------
// Author: wleggette
//
// Date: Oct 25, 2007
//---------------------

package org.jscsi.scsi.protocol;
import java.io.IOException;
import java.nio.ByteBuffer;

/**
 * An object capable of encoding itself to a byte array and decoding itself from a byte buffer.
 */
public interface Encodable
{
   byte[] encode();
   
   /**
    * Causes the encodable object to decode itself from the given byte buffer. If the associated
    * serializer has decoding any header, that header will be provided to the encodable object
    * for any additional processing.
    * 
    * @param header Any header bytes needed for additional processing.
    * @param buffer A byte buffer whose current position is at the beginning of the serialized
    *    encodable object or at the beginning plus the header length (for pre-parsed headers).
    * @throws IOException If the object could not be decoded from the input data.
    */
   void decode( byte[] header, ByteBuffer buffer ) throws IOException;
}


