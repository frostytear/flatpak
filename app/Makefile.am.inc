bin_PROGRAMS += \
	flatpak \
	$(NULL)

EXTRA_DIST += app/parse-datetime.y

flatpak_SOURCES = \
	app/flatpak-main.c \
	app/flatpak-builtins.h \
	app/flatpak-builtins-utils.h \
	app/flatpak-builtins-utils.c \
	app/flatpak-transaction.h \
	app/flatpak-transaction.c \
	app/flatpak-builtins-add-remote.c \
	app/flatpak-builtins-delete-remote.c \
	app/flatpak-builtins-list-remotes.c \
	app/flatpak-builtins-ls-remote.c \
	app/flatpak-builtins-info-remote.c \
	app/flatpak-builtins-install.c \
	app/flatpak-builtins-override.c \
	app/flatpak-builtins-make-current.c \
	app/flatpak-builtins-update.c \
	app/flatpak-builtins-uninstall.c \
	app/flatpak-builtins-list.c \
	app/flatpak-builtins-info.c \
	app/flatpak-builtins-config.c \
	app/flatpak-builtins-run.c \
	app/flatpak-builtins-enter.c \
	app/flatpak-builtins-build-init.c \
	app/flatpak-builtins-build.c \
	app/flatpak-builtins-build-finish.c \
	app/flatpak-builtins-build-export.c \
	app/flatpak-builtins-build-bundle.c \
	app/flatpak-builtins-build-import-bundle.c \
	app/flatpak-builtins-build-commit-from.c \
	app/flatpak-builtins-build-sign.c \
	app/flatpak-builtins-repo-update.c \
	app/flatpak-builtins-repo.c \
	app/flatpak-builtins-document-export.c \
	app/flatpak-builtins-document-unexport.c \
	app/flatpak-builtins-document-info.c \
	app/flatpak-builtins-document-list.c \
	app/flatpak-builtins-search.c \
	app/parse-datetime.h \
	$(NULL)

nodist_flatpak_SOURCES = \
	app/parse-datetime.c \
	$(NULL)

app/parse-datetime.c: app/parse-datetime.y Makefile
	$(AM_V_GEN) $(YACC) $< -o $@

CLEANFILES += app/parse-datetime.c

flatpak_LDADD = $(AM_LDADD) $(BASE_LIBS) $(OSTREE_LIBS) $(SOUP_LIBS) $(JSON_LIBS) $(APPSTREAM_GLIB_LIBS) \
	libglnx.la libflatpak-common.la
flatpak_CFLAGS = $(AM_CFLAGS) $(BASE_CFLAGS) $(OSTREE_CFLAGS) $(SOUP_CFLAGS) $(JSON_CFLAGS) $(APPSTREAM_GLIB_CFLAGS) \
        -I$(srcdir)/app \
        -DLOCALEDIR=\"$(localedir)\"
