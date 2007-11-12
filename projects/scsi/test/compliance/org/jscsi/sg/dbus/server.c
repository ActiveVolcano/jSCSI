#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <dbus/dbus-glib-bindings.h>
#include <glib/gprintf.h>

typedef struct SGDataTransfer SGDataTransfer;
typedef struct SGDataTransferClass SGDataTransferClass;

GType s_g_data_transfer_get_type (void);

struct SGDataTransfer
{
  GObject parent;
};

struct SGDataTransferClass
{
  GObjectClass parent;
};


#define S_G_DATA_TRANSFER_TYPE_OBJECT    (s_g_data_transfer_get_type ())

G_DEFINE_TYPE(SGDataTransfer, s_g_data_transfer, G_TYPE_OBJECT)

gboolean 
service_response(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun, const GArray* IN_senseData,
                 const gint32 IN_status, const gint32 IN_serviceResponse, GError **error);

gboolean 
send_data_in(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun, const GArray* IN_input);


GArray* 
receive_data_out(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun);

#include "s_g_data_transfer.h"

static void
s_g_data_transfer_init (SGDataTransfer *obj)
{
}

static void
s_g_data_transfer_class_init (SGDataTransferClass *klass)
{
}

gboolean 
service_response(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun, const GArray* IN_senseData,
                 const gint32 IN_status, const gint32 IN_serviceResponse, GError **error)
{
   g_printf("In method: service_response()\n");

   // implement
   if(1)
   {

      return TRUE;
   }
   else
   {
      // set error using g_set_error method
      return FALSE;
   }
}


gboolean 
send_data_in(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun, const GArray* IN_input)
{
   g_printf("In method: send_data_in()\n");

   // implement
   return TRUE;
}


GArray* 
receive_data_out(SGDataTransfer* dataTransfer, const char * IN_initiatorPort, 
                 const char * IN_targetPort, const gint64 IN_lun)
{
   g_printf("In method: receive_data_out()\n");

   // implement
   return 0;
}


int
main (int argc, char **argv)
{
   DBusGConnection *connection;
   GError *error;
   SGDataTransfer *dataTransfer;
   GMainLoop *mainloop;
  
   g_printf("starting server...\n");

   g_type_init ();

   // Install type 
   dbus_g_object_type_install_info (S_G_DATA_TRANSFER_TYPE_OBJECT, &dbus_glib_s_g_data_transfer_object_info);

   mainloop = g_main_loop_new (NULL, FALSE);

   // Create a connection
   error = NULL;
   connection = dbus_g_bus_get (DBUS_BUS_SYSTEM,
                                &error);
   if (connection == NULL)
   {
      g_printerr ("Failed to open connection to bus: %s\n",
                  error->message);
      g_error_free (error);
      exit (1);
   }
   
   g_printf("connection to bus established\n");

   // Create the object
   dataTransfer = g_object_new (S_G_DATA_TRANSFER_TYPE_OBJECT, NULL); 

   if (dataTransfer == NULL)
   {
      g_printerr ("Failed to create g_object!");
      exit (1);
   }

   g_printf("SGDataTransfer object created\n");

   // Registering the object should export it to the BUS
   dbus_g_connection_register_g_object (connection,
                                        "/org/jscsi/sg/dbus/SGDataTransfer",
                                        G_OBJECT(dataTransfer));

   g_printf("object exported\n");

   g_main_loop_run (mainloop);
   
   exit(0);
}


