/*
 * Copy me if you can.
 * by 20h
 */

#ifndef ARG_H__
#define ARG_H__

extern char *argv0;

/* use main(int argc, char *argv[]) */
#define ARGBEGIN \
			for (argv0 = *argv, argv++, argc--;                  \
			     argv[0] && argv[0][0] == '-' && argv[0][1];     \
			     argc--, argv++                 )                \
			{                                                    \
				char arg_;                                   \
				int brk_;                                    \
				if (argv[0][1] == '-' && argv[0][2] == '\0') \
				{                                            \
					argv++;                              \
					argc--;                              \
					break;                               \
				}                                            \
				for (brk_ = 0, argv[0]++;                    \
				     !brk_ && (arg_ = argv[0][0]);           \
				     argv[0]++             )                 \
				{                                            \
					switch (arg_)
#define ARGEND \
				} \
			}

#define _ARGF(x)	\
			( (argv[0][1] == '\0' && argv[1] == NULL)  \
			  ? (x)                                    \
			  : (brk_ = 1, ( (++argv[0]) [0] != '\0')  \
			               ? argv[0]                   \
			               : ( argc--, (++argv)[0] )   \
			    )                                      \
			)

#define ARGC()		arg_

#define EARGF(x) (_ARGF( ((x), abort(), NULL) ))

#define ARGF()   (_ARGF( NULL ))

#endif
