Overview
========

jSCSI is the first Java iSCSI initiator continuously developed since 2006. Entirely written in Java, it allows easy access to iSCSI as block-accessing protocol from both sides, server(target) and client(initiator).

The iSCSI protocol
------------------

The iSCSI protocol defines how a client (iSCSI initiator) accesses a block device on a server (iSCSI target) over a TCP/IP network. It is inspired by the existing SCSI protocol used to access local hard drives or other devices in a block-oriented fashion. 
Being standardized in April 2004 with [RFC 3720](http://www.ietf.org/rfc/rfc3720.txt), it was quickly	adopted, not least because it is believed to offer a better price-performance ratio and fewer infrastructure changes than competing solutions such as fibre channel. 
Furthermore, recent research indicates that user-level iSCSI initiators can improve performance considerably.

jSCSI - a plain Java iSCSI framework
------------------------------------

jSCSI includes a Java iSCSI initiator and a Java iSCSI target. Besides an initiator and target implementation, jSCSI furthermore offers convenient methods to parse PDUs independently from the concrete appliance as server or client. Entirely written in Java, jSCSI offers easy possibilities to be extended while staying completely platform independent.

jSCSI initiator
---------------

The jSCSI-initiator is represented by a library offering easy access to (nearly) any iSCSI target. The interface is leaned on common IO-interfaces making adapters quite easy. Leveraging from the easy utilization of multiple threads within Java, the initiator is able to work on Multi-Connection/Session as well as on Multi-Session basis. For more information, please refer to the initiator-bundle.

Based on its simple appliance as plain Java-library, our initiator is suited to act as a base for any low-level based operation. Examples of such applications include a storage-pool as well as a block-visualization. For more information, please refer to the intiatorExtensions-bundle.

jSCSI target
------------

The target at the moment enables users either to start it as a demon process storing all blocks in a simple RandomAccessFile. Abstraction for using other storages as well as a library-based handling instead of a utilization as demon are supported. For more information, please refer to the target-bundle.

Our target is suited to act as a base for further target-allocated applications like the SCSI-layer implementation from Cleversafe. For more information, please refer to the targetExtensions-bundle.

Who worked on jSCSI?
--------------------

jSCSI was created at the [Distributed Systems Group](http://www.informatik.uni-konstanz.de/arbeitsgruppen/disy/) from the [university of Konstanz](http://www.uni-konstanz.de/). jSCSI is licensed under the [BSD3-Clause Licence](http://www.opensource.org/licenses/BSD-3-Clause) offering easy ways to utilize the provided library. 
The project was started in 2006 by Marc Kramis and transferred in 2007 to Sebastian Graf. Since its beginning, jSCSI acts as a base for student projects. The following students contributed to this project:

Volker Wildi, jSCSI Initiator 1.0
Halldor Janetzko, Whiskas Block-Visualization
Bastian Lemke, jSCSI Storage Pool
Markus Specht, jSCSI Target evaluation
Patrice Brend'amour, jSCSI Initiator 2.0
Andreas Ergenzinger, jSCSI Target 1.0
Nuray GÃ¼rler, jSCSI websites
Andreas Rain, Test-cases
Within the switch of the hosting from [Sourceforge](http://sourceforge.net/projects/jscsi/) to [github](https://github.com/disy), jSCSI experiences impacts from the open-source community directly. The following companies provided features within jSCSI:
SCSI-layer; Thank you, Cleversafe
Flexible disk-size; Thank you,
Multiple target-handling within one instance; Thank you,
