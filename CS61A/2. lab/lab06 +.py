# Similar problems as Lab6 for more practice, generated by Claude 3.5 Sonnet
# Library System
class Book:
    """A book has the following attributes:

    title (str): the title of the book
    author (str): the author of the book
    isbn (str): unique identifier for the book
    available (bool): whether the book is currently available
    condition (int): condition rating from 1-5, decreases with each borrow

    >>> book = Book("The Hobbit", "Tolkien", "978-0547928227", 5)
    >>> book.title
    'The Hobbit'
    >>> book.condition
    5
    >>> book.available
    True
    """

    def __init__(self, title, author, isbn, condition):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.condition = condition
        self.available = True

    def borrow(self):
        """Mark the book as unavailable and decrease its condition by 1.
        Returns False if book is already borrowed or condition would drop below 1.

        >>> book = Book("The Hobbit", "Tolkien", "978-0547928227", 2)
        >>> book.borrow()
        True
        >>> book.available
        False
        >>> book.condition
        1
        >>> book.borrow() # Can't borrow an unavailable book
        False
        """
        if self.available and self.condition > 1:
            self.condition -= 1
            self.available = False
            return True
        return False

    def return_book(self):
        """Mark the book as available again.
        Returns False if book is already available.

        >>> book = Book("The Hobbit", "Tolkien", "978-0547928227", 3)
        >>> book.borrow()
        True
        >>> book.return_book()
        True
        >>> book.available
        True
        >>> book.return_book() # Can't return an available book
        False
        """
        if self.available:
            return False
        self.available = True
        return True


class Member:
    """A library member that can borrow books.

    >>> library = Library()
    >>> book = Book("1984", "Orwell", "978-0451524935", 4)
    >>> library.add_book(book)
    >>> member = Member("John Doe", "12345", library)
    >>> member.borrow_book("978-0451524935")
    True
    >>> len(member.borrowed_books)
    1
    >>> member.return_book("978-0451524935")
    True
    >>> len(member.borrowed_books)
    0
    """

    def __init__(self, name, member_id, library):
        self.name = name
        self.member_id = member_id
        self.library = library
        self.borrowed_books = []
        library.register_member(self)

    def borrow_book(self, isbn):
        """Attempt to borrow a book from the library by ISBN."""
        book = self.library.get_book(isbn)
        if book and book.borrow():
            self.borrowed_books.append(isbn)
            return True
        return False

    def return_book(self, isbn):
        """Return a borrowed book to the library."""
        if isbn not in self.borrowed_books:
            return False
        book = self.library.get_book(isbn)
        if book and self.return_book:
            self.borrowed_books.remove(isbn)
            return True
        return False


class Library:
    """A library manages a collection of books and members.

    >>> library = Library()
    >>> book = Book("Dune", "Herbert", "978-0441172719", 5)
    >>> library.add_book(book)
    >>> book2 = Book("Neuromancer", "Gibson", "978-0441569595", 3)
    >>> library.add_book(book2)
    >>> library.get_book("978-0441172719").title
    'Dune'
    >>> library.get_available_books()
    2
    """

    def __init__(self):
        self.books = {}  # isbn -> Book
        self.members = {}  # member_id -> Member

    def add_book(self, book):
        """Add a new book to the library."""
        self.books[book.isbn] = book

    def register_member(self, member):
        """Register a new member with the library."""
        self.members[member.member_id] = member

    def get_book(self, isbn):
        """Return the book with the given ISBN, or None if not found."""
        if self.books[isbn]:
            return self.books[isbn]
        return None

    def get_available_books(self):
        """Return the number of books currently available for borrowing."""
        return sum(1 for book in self.books.values() if book.available)


# Social Media Post System
class Post:
    """A social media post that tracks its likes, shares and engagement score.

    >>> post = Post("Hello World!", "Alice")
    >>> post.content
    'Hello World!'
    >>> post.author
    'Alice'
    >>> post.likes
    0
    >>> post.shares
    0
    >>> post.calculate_engagement()
    0.0

    # Test liking functionality
    >>> post.add_like("Bob")
    'Thanks for liking!'
    >>> post.likes
    1
    >>> post.add_like("Bob")  # Try to like again
    'You already liked this post!'
    >>> post.likes  # Likes shouldn't increase
    1
    >>> post.add_like("")  # Empty username
    'Invalid username!'
    >>> post.likes  # Likes shouldn't increase
    1
    >>> post.calculate_engagement()  # 1 like = 0.1 score
    0.1

    # Test sequential likes
    >>> post.add_like("Charlie")
    'Thanks for liking!'
    >>> post.add_like("David")
    'Thanks for liking!'
    >>> post.likes
    3
    >>> post.calculate_engagement()  # 3 likes = 0.3 score
    0.3

    # Test sharing functionality
    >>> post.share("", "Bob")  # Empty sharer username
    'Invalid username!'
    >>> post.share("Bob", "")  # Empty recipient username
    'Invalid username!'
    >>> post.shares  # Invalid shares shouldn't count
    0
    >>> post.share("Bob", "Charlie")  # Valid share
    1
    >>> post.shares
    1
    >>> post.share("Charlie", "David")  # Continuing the chain
    2
    >>> post.shares
    2
    >>> post.share("Eve", "Frank")  # New chain
    1
    >>> post.shares
    3
    >>> post.calculate_engagement()  # (3 likes + 3*2 shares) / 10 = 0.9
    0.9

    # Test engagement score cap
    >>> for i in range(10):  # Add many more likes
    ...     post.add_like(f"user{i}")
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    >>> post.calculate_engagement()  # Score should be capped at 1.0
    1.0
    """

    def __init__(self, content, author):
        self.content = content
        self.author = author
        self.likes = 0
        self.shares = 0
        self._likers = []  # Private list to track who liked
        self._sharing_history = []  # Private list to track sharing chain

    def add_like(self, user_name):
        """Add a like to the post if the user hasn't already liked it."""
        if user_name and user_name not in self._likers:
            self._likers.append(user_name)
            self.likes += 1
            return 'Thanks for liking!'
        elif not user_name:
            return 'Invalid username!'
        else:
            return 'You already liked this post!'

    def share(self, shared_by, shared_to):
        """Track the sharing chain of the post and update engagement."""
        if not shared_by or not shared_to:
            return 'Invalid username!'
        self.shares += 1
        for i in self._sharing_history:
            if i[-1] == shared_by:
                i.append(shared_to)
                return len(i) - 1
        self._sharing_history.append([shared_by, shared_to])
        return 1

    def calculate_engagement(self):
        """Calculate engagement score based on likes and shares."""
        score = (self.likes * 1 + self.shares * 2) / 10
        return min(1.0, round(score, 1))


class Feed:
    """A feed that manages posts and tracks trending content.

    >>> feed = Feed()
    >>> len(feed.posts)
    0

    # Test adding posts
    >>> post1 = Post("First post!", "Alice")
    >>> post2 = Post("Second post!", "Bob")
    >>> feed.add_post(post1)
    >>> len(feed.posts)
    1
    >>> feed.add_post(post2)
    >>> len(feed.posts)
    2
    >>> feed.add_post(post1)  # Try to add same post again
    'Post already exists!'
    >>> len(feed.posts)  # Length shouldn't change
    2

    # Test removing posts
    >>> feed.remove_post(Post("Non-existent post", "Charlie"))  # Try to remove non-existent post
    'Post not found!'
    >>> len(feed.posts)  # Length shouldn't change
    2
    >>> feed.remove_post(post1)
    'Post removed successfully!'
    >>> len(feed.posts)
    1
    >>> feed.remove_post(post1)  # Try to remove already removed post
    'Post not found!'

    # Test trending posts
    >>> viral_post = Post("Viral content!", "Charlie")
    >>> feed.add_post(viral_post)
    >>> regular_post = Post("Regular content!", "David")
    >>> feed.add_post(regular_post)
    >>> len(feed.posts)
    3

    # Make viral_post trending
    >>> for i in range(6):  # Add 6 likes
    ...     viral_post.add_like(f"user{i}")
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'

    >>> viral_post.calculate_engagement()  # 6 likes = 0.6 score
    0.6
    >>> len(feed.get_trending_posts(0.5))  # Should include viral_post
    1
    >>> len(feed.get_trending_posts(0.7))  # Threshold too high
    0
    >>> len(feed.get_trending_posts(0))  # Zero threshold includes all posts
    3
    """

    def __init__(self):
        self.posts = []

    def add_post(self, post):
        """Add a post to the feed if it doesn't already exist."""
        if post not in self.posts:
            self.posts.append(post)
            return None
        return 'Post already exists!'

    def remove_post(self, post):
        """Remove a post from the feed if it exists."""
        if post in self.posts:
            self.posts.remove(post)
            return 'Post removed successfully!'
        return 'Post not found!'

    def get_trending_posts(self, threshold = 0.5):
        """Return a list of posts with engagement score >= threshold."""
        return [post for post in self.posts if post.calculate_engagement()>=threshold]


class UserProfile:
    """A user profile that manages posts and tracks influence score.

    >>> profile = UserProfile("Alice")
    >>> profile.username
    'Alice'
    >>> len(profile.posts)
    0

    # Test post creation
    >>> profile.create_post("")  # Empty content
    'Post content cannot be empty!'
    >>> len(profile.posts)  # No post should be created
    0
    >>> profile.create_post("Hello everyone!")
    'Post created successfully!'
    >>> len(profile.posts)
    1
    >>> profile.posts[0].author
    'Alice'
    >>> profile.posts[0].content
    'Hello everyone!'

    # Test influence calculation
    >>> profile.calculate_influence()  # No engagement yet
    0.0
    >>> profile.create_post("Second post!")
    'Post created successfully!'
    >>> profile.posts[0].add_like("Bob")
    'Thanks for liking!'
    >>> profile.posts[0].add_like("Charlie")
    'Thanks for liking!'
    >>> profile.calculate_influence()  # (0.2 + 0) / 2 = 0.1
    0.1

    # Test multiple posts and higher engagement
    >>> profile.create_post("Viral post!")
    'Post created successfully!'
    >>> for i in range(5):  # Add likes to make it viral
    ...     profile.posts[2].add_like(f"user{i}")
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    'Thanks for liking!'
    >>> profile.posts[2].share("user1", "user2")
    1
    >>> profile.calculate_influence()  # (0.2 + 0 + 0.7) / 3 ≈ 0.3
    0.3
    """

    def __init__(self, username):
        if not username:
            raise ValueError("Username cannot be empty!")
        self.username = username
        self.posts = []
        self.feed = Feed()

    def create_post(self, content):
        """Create a new post and add it to personal posts and feed."""
        if not content:
            return 'Post content cannot be empty!'
        post = Post(content, self.username)
        self.posts.append(post)
        self.feed.add_post(post)
        return 'Post created successfully!'

    def calculate_influence(self):
        """Calculate user's influence score based on their posts' engagement."""
        if not self.posts:
            return 0.0
        total_engagement = sum(post.calculate_engagement() for post in self.posts)
        return round(total_engagement / len(self.posts), 1)