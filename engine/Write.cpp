//////////////////////////////////////////////////////////////////////////
//                                                                      //
//   BOOM 2 Engine                                                      //
//                                                                      //
//   write.cpp - basic writting functions implementation                //
//                                                                      //
//   by Ivaylo Beltchev                                                 //
//   e-mail: ivob@geocities.com                                         //
//   www:    www.geocities.com/SiliconValley/Bay/2234                   //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#define _WRITE_CPP
#include "write.h"

#include <io.h>
#include <fcntl.h>

#ifdef _MSC_VER
#include <sys\stat.h>
#ifndef S_IRWXU
#define S_IRWXU _S_IREAD | _S_IWRITE
#endif
#endif

static int fd;

// opens a file for writting
void write_start( char *fn )
{
  fd=open(fn,O_RDWR|O_CREAT|O_BINARY,S_IRWXU);
}

// closes the current file
bool write_end()
{
  close(fd);
  fd=-1;
  return true;
}

// writes size bytes from buf to the current file
void wrbuf( void *buf, unsigned size )
{
  write(fd,buf,size);
}

// writes a 4 byte integer
void wrlong( long buf )
{
  write(fd, &buf, sizeof(buf) );
}

// writes a 2 byte integer
void wrshort( short buf )
{
  write(fd, &buf, sizeof(buf) );
}

// writes a 1 byte integer
void wrchar( char buf )
{
  write(fd, &buf, sizeof(buf) );
}

// writes a float
void wrfloat( float buf )
{
  write(fd, &buf, sizeof(buf) );
}
