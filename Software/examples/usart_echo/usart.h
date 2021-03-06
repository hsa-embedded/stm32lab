/*
# usart.h
# Copyright (C) 2014 Ferdinand Saufler
# 
# this is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# this software is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define BUFFER_LENTH 1024

void usart_sendc(char c);
void usart_sends(char* c);
int write_buffer(char c, char* buf);
int read_buffer(char* buf);
void clear_buffer(void);
void usart_init(void);

/*
vim: et sw=4 ts=4
*/
