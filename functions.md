# Application Functions Reference

This document outlines all the functions used across the different modules in the Game Store application, categorized by system logic.

## 1. Catalog (`catalog.c` / `catalog.h`)
- `catalog_init(Catalog *catalog)`: Initializes an empty catalog with a pre-defined array of starter games.
- `catalog_get_game(Catalog *catalog)`: Returns a pointer to the core array holding all catalog games.
- `catalog_sort_by_price(Catalog *catalog)`: Sorts the catalog's game list in ascending order of price using insertion sort.
- `catalog_sort_by_rating(Catalog *catalog)`: Sorts the catalog's game list in descending order of rating (highest rated games appear first).
- `catalog_search_by_id(Catalog *catalog, int id)`: Searches for a specific game sequentially by ID and returns its memory address.
- `catalog_get_count(Catalog *catalog)`: Returns the total number of games available to display in the catalog.
- `catalog_destroy(Catalog *catalog)`: Included for structural completeness to safely unmount memory at the end of execution.

## 2. Cart (`cart.c` / `cart.h`)
- `cart_init(Cart *cart)`: Initializes an empty shopping cart (setup as a doubly linked list).
- `cart_add_game(Cart *cart, Game *game)`: Appends a newly targeted catalog game to the tail of the cart structure.
- `cart_search_by_id(Cart *cart, int ID)`: Finds a specific pending cart transaction by ID.
- `cart_remove_by_id(Cart *cart, int removeID)`: Selectively unlinks a targeted game from anywhere within the cart and updates pointers cleanly.
- `cart_get_total_price(Cart *cart)`: Sums up the prices of all items currently residing in the cart to present a total string.
- `cart_get_count(Cart *cart)`: Returns the numeric total of items queued for checkout.
- `cart_get_items(Cart *cart)`: Emits the head pointer of the cart, used iteratively to check out all contents simultaneously.
- `cart_clear(Cart *cart)`: Iteratively scrubs all node elements inside the cart, safely freeing their heap mappings.
- `cart_destroy(Cart *cart)`: Centralized entrypoint to deconstruct the cart array cleanly.

## 3. Library (`library.c` / `library.h`)
- `lib_init(Library *library)`: Bootstraps the user's purchased games library with a predefined structural scaling limit.
- `lib_add_game(Library *library, Game *inputGame)`: Safely loads a purchased game onto the backend, utilizing `realloc()` dynamically if the existing game array ceiling is reached.
- `lib_game_index(Library *library, int id)`: Fetches a purchased game's absolute internal array index.
- `lib_is_id_contains(Library *library, int id)`: Fast logic check mapping to `1` or `0` depending on whether a user formally holds ownership of a specific game.
- `lib_remove_game_by_id(Library *library, int id)`: Removes a targeted game from internal storage and cleanly shifts all remaining array values sequentially downward to patch empty space.
- `lib_get_game_data(Library *library, int id)`: Surfaces a pointer targeting raw internal logic structures for owned games.
- `lib_get_count(Library *library)`: Returns the discrete array size logic.
- `lib_destroy(Library *library)`: Releases the dynamically allocated underlying memory blocks assigned during `lib_add_game` extensions.

## 4. Download Manager (`download.c` / `download.h`)
- `download_init_queue(DownloadQueue *queue)`: Primes the memory structure required to coordinate a download queue layout.
- `download_is_empty(DownloadQueue *queue)`: Logic flag indicating if active download items exist currently.
- `download_enqueue(DownloadQueue *queue, Game *game)`: Locks onto a new backend pointer and explicitly mounts the requested game application at the far rear of the underlying queue lines.
- `download_dequeue(DownloadQueue *queue)`: Pops the uppermost element directly off the front of the queue sequentially to clear installed entries.
- `download_peek(DownloadQueue *queue)`: Fetches internal system identifiers referencing strictly what lies at the foremost array stack without executing any pops.
- `download_remove_by_id(DownloadQueue *queue, int id)`: Iterates securely through the active download nodes to isolate and terminate a targeted sequence by ID mid-progress.
- `download_is_duplicate(DownloadQueue *queue, int id)`: Internal security mechanic deployed during queuing mechanisms to avert duplicate instances of the same structural download.
- `download_queue_destroy(DownloadQueue *queue)`: Collapses remaining pointers sequentially upon exit bounds.

## 5. Support Tickets (`support.c` / `support.h`)
- `support_queue_initialize(priorityQueue *q)`: Boots up an active stream mapping consisting of various pre-built tickets.
- `support_queue_submit_ticket(priorityQueue *q, int ticketID, char ticketTitle[], int priority)`: Builds a backend structure and directly forces a sorted injection point depending exclusively on a ticket's integer scaling priority severity (`1` being maximum severity).
- `support_queue_resolve_next(priorityQueue *q)`: Systematically drops the absolute highest urgency node currently situated at mapping `front`.
- `support_queue_peek_next(priorityQueue *q)`: Emits core data points representing whatever string sits uppermost in structural priority layouts.
- `support_queue_get_count(priorityQueue *q)`: Returns absolute quantity bounds mapping total unhandled objects.
- `support_queue_destroy(priorityQueue *q)`: Iterative collapse structure terminating any unprocessed support flags entirely securely.

## 6. Wishlist (`wishlist.c` / `wishlist.h`)
- `wishlist_init(Wishlist *wishlist)`: Configures the starting head/tail bounds required to sustain linked list elements scaling.
- `createNode(Game *game)`: Hidden allocation struct generating backend memory payloads exclusively containing object identifiers.
- `wishlist_isEmpty(Wishlist *wishlist)`: Flag sequence parsing if sequence nodes physically populate the matrix boundaries.
- `wishlist_insert_new_item(Wishlist *wishlist, Game *game)`: Forces an object expansion connecting tail node paths directly to newly requested sequence boundaries.
- `wishlist_search_game_by_id(Wishlist *wishlist, int ID)`: Validates node boundaries tracking isolated matching structural game identifiers across linked elements.
- `wishlist_remove_item_by_id(Wishlist *wishlist, int removeID)`: Pinpoints localized sequence occurrences by ID layout, re-maps local previous/next pointers concurrently to bypass node, and then flushes node locally.
- `wishlist_display_contains(Wishlist *wishlist)`: Core extraction outputting formatted sequence string lines reflecting the current array.
- `wishlist_count(Wishlist *wishlist)`: Total volume limit tracker.
- `wishlist_clear(Wishlist *wishlist)`: Sequential destruction unmounting heap payload blocks universally.
- `wishlist_destroy(Wishlist *wishlist)`: Triggers core bounds wipe.

## 7. Navigation (`navigation.c` / `navigation.h`)
- `nav_init(NavStack *nav)`: Struct initialization of application menu mechanics utilizing internal stack boundaries.
- `nav_push(NavStack *nav, Page page)`: Explicitly injects top-level layout enums tracking where users presently traverse dynamically.
- `nav_pop(NavStack *nav)`: Backtracks one step out sequentially when a local escape flag (like `0`) is triggered.
- `nav_peek(NavStack *nav)`: Examines absolute uppermost matrix limits dictating which layout frame visually renders at any given point natively. 
- `nav_is_empty(NavStack *nav)`: Checks if the user logic has completely stepped out of every mapped sub-component tree.
- `nav_destroy(NavStack *nav)`: Recursively strips lingering backend pointers remaining during a hard application loop termination sequence natively.

## 8. Main UI Logic (`main.c`)
- `show_main_menu()`: Responsible for exclusively painting aesthetic ASCII boundaries denoting core directory endpoints natively.
- `handle_wishlist_menu(...)`: Manages the user inputs allowing transitionary flows specifically enabling users to ferry structural items immediately from Wishlists sequentially into Shopping Carts natively.
- `display_downloads(...)` & `handle_downloads_menu(...)`: Encapsulates output mapping displaying any enqueued structural payloads currently waiting for deployment natively while handling node dropping functions contextually.
- `display_library(...)` & `handle_library_menu(...)`: Renders structural ownership grids confirming active inventory status arrays, whilst opening up bridging channels directly pushing user objects actively down the payload `dQueue` lines.
- `display_catalog(...)` & `handle_catalog_menu(...)`: Heaviest processing node tracking the central core application loop mapping out items array boundaries dynamically, accepting local sorting instruction overrides sequentially, and directing new game bounds directly to active memory endpoints dynamically. 
- `display_cart_menu(...)` & `handle_cart_menu(...)`: Core execution pipeline bridging transaction bounds securely. Resolves queued limits actively pushing validated items inherently through ownership structural arrays, followed immediately internally appending bounds natively into active user queues securely.
- `display_support(...)` & `handle_support_menu(...)`: Provides visual UI mapping arrays natively displaying the current sorting structure bounds dynamically while simulating ticket pop triggers.
