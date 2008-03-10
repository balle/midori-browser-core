/*
 Copyright (C) 2008 Christian Dywan <christian@twotoasts.de>

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 See the file COPYING for the full license text.
*/

#ifndef __MIDORI_BROWSER_H__
#define __MIDORI_BROWSER_H__

#include <webkit/webkit.h>

#include <katze/katze.h>

G_BEGIN_DECLS

#define MIDORI_TYPE_BROWSER \
    (midori_browser_get_type ())
#define MIDORI_BROWSER(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), MIDORI_TYPE_BROWSER, MidoriBrowser))
#define MIDORI_BROWSER_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST ((klass), MIDORI_TYPE_BROWSER, MidoriBrowserClass))
#define MIDORI_IS_BROWSER(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MIDORI_TYPE_BROWSER))
#define MIDORI_IS_BROWSER_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), MIDORI_TYPE_BROWSER))
#define MIDORI_BROWSER_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), MIDORI_TYPE_BROWSER, MidoriBrowserClass))

typedef struct _MidoriBrowser                MidoriBrowser;
typedef struct _MidoriBrowserPrivate         MidoriBrowserPrivate;
typedef struct _MidoriBrowserClass           MidoriBrowserClass;

struct _MidoriBrowser
{
    GtkWindow parent_instance;

    MidoriBrowserPrivate* priv;
};

struct _MidoriBrowserClass
{
    GtkWindowClass parent_class;

    /* Signals */
    void
    (*quit)                    (MidoriBrowser*       browser);
    void
    (*new_window)              (MidoriBrowser*       browser,
                                const gchar*         uri);
};

GType
midori_browser_get_type               (void);

GtkWidget*
midori_browser_new                    (void);

gint
midori_browser_append_tab             (MidoriBrowser*     browser,
                                       GtkWidget*         widget);

void
midori_browser_remove_tab             (MidoriBrowser*     browser,
                                       GtkWidget*         widget);

gint
midori_browser_append_xbel_item       (MidoriBrowser*     browser,
                                       KatzeXbelItem*     xbel_item);

gint
midori_browser_append_uri             (MidoriBrowser*     browser,
                                       const gchar*       uri);

GtkWidget*
midori_browser_get_current_page       (MidoriBrowser*     browser);

GtkWidget*
midori_browser_get_current_web_view   (MidoriBrowser*     browser);

KatzeXbelItem*
midori_browser_get_proxy_xbel_folder  (MidoriBrowser*     browser);

G_END_DECLS

#endif /* __MIDORI_BROWSER_H__ */
