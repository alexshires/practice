#! /usr/bin/env python

import sqlite3 as sq
conn = sq.connect("test.db")
c = conn.cursor()
c.execute("CREATE TABLE data (v1, v2, v3)")
c.execute("INSERT INTO data VALUES ( 1,2,3 )")
conn.commit()
conn.close()
