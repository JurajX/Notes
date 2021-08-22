https://www.pygame.org/docs/

import pygame, sys
from pygame.locals import *

pygame.init()
pygame.quit()
sys.exit()


------------------------------------------pygame

.init()                                   # F; initializes each pygame module.
.module.init()                            # F; initializes only specific module.
.quit()                                   # F; frees up resources.
.module.quit()                            # F; frees up resources from module.

Surface(resolution)                       # OC; represents a rectanular 2D image.
    .convert_alpha()                      # MF; returns a Surface alowing for alpha value in colours.
    .fill(color)                          # MF; fills the surface with color.
    .get_locked()                         # MF; returns bool depending on the locked/unlocked status of the surface.
    .get_rect()                           # MF; returns Rect obj with top=0, left=0, and dimensions of the surface.
    .blit(surface1, (tlX, tlY))           # MF; copies surface1 onto the (unlocked) surface, coos of the top left corner.
    .set_colorkey(color)                  # MF; sets every pixel having colour same as color to transparent.
    .get_colorkey()                       # MF; returns current transparent colorkey.

Rect(tlX,tlY,W,H)                         # OC; represents a rectangular area, top left X,Y and width, height.
    .left .right .top .bottom             # A; int values of the edges of the rectangle.
    .topleft .topright
    .bottomleft .bottomright
    .midleft .midright .midtop .midbottom
    .centerx .centery .center             # A; coordinates of the centre, X, Y, touple.
    .width .height .size                  # A; width, height, (width, height)
    .collidepoint(x,y)                    # MF; checks if the pixes x,y is in the rectangle.

PixelArray(surface)                       # OC; locks surface and allows for individual pixel change.
    [X][Y]                                # accessing an individual pixel.
    del PixArr                            # deletes the pixel array object and unlocks the surface.

Color(R,G,B,A)                            # OC; represents a colour, use 3 or 4 integers.


------------------------------------------pygame.draw

polygon(surface, colour, pts, width)      # F; polygon, pts -> list/tuple of X-Y coos, width=0 fills the polygon.
lines(surface, colour, closed, pts, width)# F; like polygon, if closed=False no line from the last pt to the first pt.
aalines()                                 # F; same as above but anti-aliased (smooth).
line(surface, colour, pt, pt, width)      # F; line, start/end pts, width.
aaline()                                  # F; same as above but anti=aliased (smooth).
circle(surface, colour, pt, r, width)     # F; circle, pt is centre.
ellipse(surface, colour, rect, width)     # F; ellipse, bounding rectangle is Rect obj or (tlX,tlY,W,H), c.f. Rect().
rect(surface, colour, rect, width)        # F; rectangle, rect is either Rect obj, or (tlX,tlY,W,H), c.f. Rect().


------------------------------------------pygame.image

.load('myImg')                            # F; returns a Surface obj with the image.
.convert()                                # F; converts an image to a more suitable format (game runs faster).


------------------------------------------pygame.font

Font(font_title, size)                    # OC; constructs text object with defined font type and size.
    .render('text', a-a, t_col, bg_col)   # MF; returns surface with text, anti-aliasing, colour of text and bg. 


------------------------------------------pygame.display

.set_mode(resolution, flags, depth)       # F; returns the display Surface object, touple.
.set_caption('myText')                    # F; sets the window's title.
.update(rect=None)                        # F; updates portions of the screen (corresponding to rects) for software displays.
.flip()                                   # F; updates the full display Surface to the screen.


------------------------------------------pygame.time

Clock()                                   # OC; allows to set a speed for the program loop.
    .tick(fps)                            # MF; pause for T=1/fps-t, where t is time past since the last call.



------------------------------------------pygame.mixer

Sound('mysound')                          # OC; loads the sound into the object.
    .play()                               # MF; starts playing the sound.
    .stop()                               # MF; stops playing the sound.

music.load('mySound')                     # F; loads a bg_music file.
music.play(loops=0, start=0)              # F; starts playing bg_music, number of plays (-1 for infty), where to start - float.
music.stop()                              # F; stop playing bg_music.


------------------------------------------pygame.event

.get()                                    # F; returns a list of events happened since the last call.

Event()                                   # OC; represents an event, e.g. key presses.
    .type                                 # A; eturns the type of the event.


------------------------------------------pygame.locals
# This module constants variables for each possible event type.

QUIT                                      # O; const event object.
