function connect(widget, slot, f) {
    widget[slot].connect(function() { return f.apply(widget, arguments) });
}

(function() {
    print("Hello world");
    print(Object.keys(this));

    var w = qt.loadUi(":/mainwindow.ui");
    print(w);
    print(Object.keys(w).sort());
    print(Object.getPrototypeOf(w));
    /*
    connect(w.findChild("actionHello"), "triggered", function(tf) {
        print("Hello!", this, tf);
    });
    connect(w.findChild("actionWorld"), "triggered", function() {
        print("World!", this, arguments[0]);
    });
    */
    w.show();
})();
