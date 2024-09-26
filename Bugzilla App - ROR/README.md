# Bugzilla Test App

In this project you are going to create a bug management system named bugzilla. There will be
multiple roles for a user like Manager, QA and Developer. For this project you will have to create
a ruby on rails app and use all the rails standard practices that you have just learnt. You can use
any gems or package that you need in order to complete the project. On the front end the pages
should be responsive and use bootstrap or any similar libraries that can help with it.
For any user role there should be these features:

* A user should be able to sign up and there should be appropriate validation on the sign
up form like email should be unique and some basic validation on password.

* Upon sign up user should receive a confirmation email and should only be able to login after confirming the account.

* A user should be able to login to the system using the email and password.

* A user should be able to only see the pages his role has permissions to.

* A user should be able to sign out of the system.

# Manager

* A manager can create bugs.

* A manager can see a list of all the bugs.

* A manager can assign bugs to a QA and Developer.

* A manager can update the status of a bug.

* A manager can see a list of bugs and see which QA created it and which Developer is assigned to that bug.

* A manager can change the role of any QA and Developer.

# QA

* A QA can create bugs.

* A QA can see a list of all the bugs that he created.

* A QA can update the status of the bug that he created.

* A QA can see the comments added in the bug.

# Developer

* A Developer can see a list of all the bugs that are assigned to him/her.

* A Developer can start a bug.

* A Developer can mark a bug fixed.

* A Developer can add comments in the bug.

# Bug

Bugs must have following fields:

* Title.

* Description.

* Priority.

* Estimated days to completion.