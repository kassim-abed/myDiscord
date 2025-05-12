import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk

class Menu(Gtk.Box):
    def __init__(self):
        super().__init__(orientation=Gtk.Orientation.VERTICAL, spacing=10)

        self.servers_btn = Gtk.Button(label="Servers")
        self.settings_btn = Gtk.Button(label="Settings")

        self.append(self.servers_btn)
        self.append(self.settings_btn)

class MenuWindow(Gtk.ApplicationWindow):
    def __init__(self, app):
        super().__init__(application=app)
        self.set_title("Discord Clone - Menu")
        self.set_default_size(300, 500)

        menu = Menu()
        self.set_child(menu)

class MyApp(Gtk.Application):
    def do_activate(self):
        window = MenuWindow(self)
        window.present()

app = MyApp()
app.run(None)




class MainScreen(Gtk.Box):
    def __init__(self):
        super().__init__(orientation=Gtk.Orientation.HORIZONTAL, spacing=10)

        sidebar = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        sidebar.append(Gtk.Label(label="Servers"))
        sidebar.append(Gtk.Button(label="+ Add"))

        chat_area = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        chat_area.append(Gtk.Label(label="Messages"))
        chat_input = Gtk.Entry()
        chat_area.append(chat_input)

        self.append(sidebar)
        self.append(chat_area)

class MainWindow(Gtk.ApplicationWindow):
    def __init__(self, app):
        super().__init__(application=app)
        self.set_title("Discord Clone - Main Screen")
        self.set_default_size(800, 600)

        main_screen = MainScreen()
        self.set_child(main_screen)

