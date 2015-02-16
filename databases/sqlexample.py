import sqlalchemy as sqla
from sqlalchemy import create_engine

""" docs.sqlalchemy.org/en/rel/_0_9/orm/tutorial.html """

#in memory database
engine = create_engine('postgresql:///ashires:@localhost/test',echo=True)
#


from sqlalchemy.ext.declarative import declarative_base
#base class
Base = declarative_base()
#
from sqlalchemy import Column, Integer, String

#create test class


class User(Base) :
    __tablename__ = 'users'
    uid = Column(Integer, primary_key=True)
    name = Column(String)
    def __repr__(self) : 
        return "<User(name = %s, id = %s)>" % (self.name, self.uid) 

u = User()
print u



Base.metadata.create_all(engine)

