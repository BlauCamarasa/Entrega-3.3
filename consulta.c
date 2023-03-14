#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
		MYSQL *conn;
		int err;
		MYSQL_RES *resultado;
		MYSQL_ROW row;
		int ID;
		char consulta [80];

// Ahora vamos a buscar los ids de los jugadores que hayan participado 
		// dado por el usuario
	
		printf ("Dame el id de la partida que quieres buscar sus respectivos jugadores\n"); 
		scanf ("%d", ID);
		// construimos la consulta SQL
		strcpy (consulta,"SELECT ID_J FROM REGISTRO WHERE ID_P = '"); 
		strcat (consulta, ID);
		strcat (consulta,"'");
		// hacemos la consulta 
		err=mysql_query (conn, consulta); 
		if (err!=0) {
			printf ("Error al consultar datos de la base %u %s\n",
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
		//recogemos el resultado de la consulta 
		resultado = mysql_store_result (conn); 
		row = mysql_fetch_row (resultado);
if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			printf ("ID del jugador: %s\n", row[0]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}

		// cerrar la conexion con el servidor MYSQL 
		mysql_close (conn);
		exit(0);
}
