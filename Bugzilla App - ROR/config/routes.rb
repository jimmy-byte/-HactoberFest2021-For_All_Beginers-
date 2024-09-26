Rails.application.routes.draw do
  
  #get 'session/new'
  get '/login',to: 'session#new'
  post '/login', to: 'session#create'
  delete '/logout', to: 'session#destroy'
  get '/signup',to: 'users#new'
  get 'bugs/assign/edit', to: 'assign#edit'
  get 'bugs/assign/new', to: 'assign#new'
  get 'change_role', to: 'users#change_role'
  
  resources :users 
  resources :account_activations, only: [:edit]
  resources :bugs do 
    member do
      get 'assign'
      post 'assign'
      patch 'assign'
    end

    member do 
      get 'comment'
      post 'comment'
    end

    member do 
      post 'add_comment'
      get 'add_comment'
      patch 'add_comment'
    end
  end

  resources :assign do
    member do 
      get 'assign'
    end 
  end
  root 'static_pages#home'
  
  mount LetterOpenerWeb::Engine, at: "/letter_opener" if Rails.env.development?
  

end
