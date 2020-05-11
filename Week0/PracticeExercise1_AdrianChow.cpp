#include <iostream>
#include <vector>
#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

using namespace std;

/**
 * The following class models information about a piece of artwork.
* */

class Artwork{
    string artistName;
    unsigned int yearMade;
    string artTitle;

public:

    /**
     * @brief Default Constructor
     * */

    Artwork(){ yearMade = 0;}

    /**
     * @brief Parametric Constructor
     * */
    
    Artwork(string name, int year, string title): 
        artistName(name) , yearMade(year) , artTitle(title) {}

    /**
     * @brief Overloaded Operator == (Compares Artwork classes)
     * @return true if equal
     * */
    
    bool operator==(const Artwork& target) const
    {
        bool equal = true;
        equal = equal && (artistName == target.artistName);
        equal = equal && (yearMade == target.yearMade);
        equal = equal && (artTitle ==  target.artTitle);
        return equal;

    } 


    /**
    * @brief Getter Functions for private elements in Artwork
    * @return artistName, yearMade, artTitle
    **/
 
    string getArtistName() const
    {
        return artistName;
    }

    unsigned int getYearMade() const
    {
        return yearMade;
    }          

    string getArtTitle() const
    {
        return artTitle;
    }          


};

/**
 * The following class models information about a sold piece of artwork.
 * It is recorded as an instance of SoldArtwork, a derived class of Artwork.
* */

class SoldArtwork : public Artwork{
    string customerName;
    string customerAdress;
    double saleAmount;

public:

    /**
     * @brief Empty Constructor
     **/

    SoldArtwork() {saleAmount = 0;}

    /**
    * @brief Parametric Constructor
    * */

    SoldArtwork(string name, string adresss, double cost, Artwork art): 
        customerName(name), customerAdress(adresss), saleAmount(cost), Artwork(art) {}

    /**
     * @brief Overloaded Operator == (Compares SoldArtwork class)
     * @return True if equal
     * */

    bool operator==(const SoldArtwork& target) const 
    {   
        bool equal = true;
        equal = equal && (customerName == target.customerName);
        equal = equal && (customerAdress == target.customerAdress);
        equal = equal && (saleAmount ==  target.saleAmount);
        equal = equal && (getArtistName() == target.getArtistName());
        equal = equal && (getYearMade() == target.getYearMade());
        equal = equal && (getArtTitle() == target.getArtTitle());
        return equal;
    }
    
    /**
    * @brief Getter Functions for private elements in SoldArtwork
    * @return customerName, customerAdress, saleAmount;
    **/
 
    string getCustomerName() const
    {
        return customerName;
    }

    string getCustomerAddress() const
    {
        return customerAdress;
    }          

    double getCost() const
    {
        return saleAmount;
    }          



};

/**
 * The following class stores information about a collection of artwork.
 * The Artwork and SoldArtwork instances are stored in respective vectors
* */

class ArtCollection{
    vector<Artwork> artCollection;
    vector<SoldArtwork> soldCollection;

public:

    /**
     * @brief function that adds artwork to the Art Collection
     * @condition Duplicates are returned as False
     * @param Artwork object
     * */

    bool insert_artwork(const Artwork& artwork_info)
    {

        if(artCollection.size() == 0)
        {   
            artCollection.push_back(artwork_info);
            return true;
        }

        for(int i = 0; i < artCollection.size(); i++)
        {
            if(artCollection[i] == artwork_info)
            {   
                cout << "The artpiece is a duplicate" << endl;
                return false;
            }
        }

        artCollection.push_back(artwork_info);
        return true;
    }

    /**
     * @brief function that finds corresponding artwork instance
     * removes from Artwork vector and adds the sold artwork to the sold collection.
     * @condition Duplicates are returned as False
     * @param Artwork object
     * */


    bool sell_artwork(const SoldArtwork& artwork_info)
    {
        Artwork Info(artwork_info.getArtistName() , artwork_info.getYearMade() , artwork_info.getArtTitle());
        for(int i = 0; i < artCollection.size(); i++)
        {
            if(artCollection[i] == Info)
            {
                artCollection.erase(artCollection.begin()+ i);
                soldCollection.push_back(artwork_info);
                
                return true;
            }
        }

        cout << "Could not find artpiece in collection." << endl;
        
        return false;
    }

    /**
     * @brief Overloaded Operator == (Compares ArtCollection class)
     * @return True (if two ArtCollection instances are equal)
     * */

    bool operator==(const ArtCollection& artcollection_info) const 
    {
        //Igor: Assume Equality means two artcollections contain same artwork in the same order.

        if (artCollection.size() != artcollection_info.artCollection.size()) // Size are not same
        {
            cout << "Sizes of Art Collection are not the Same" << endl;
            return false;
        }
        
        if(!(artCollection == artcollection_info.artCollection))
        {
            cout << "Art Collections are not the same" << endl;
            return false;
        }

        if (soldCollection.size() != artcollection_info.soldCollection.size()) // Size are not same
        {
            cout << "Sizes of Sold Collection are not the Same" << endl;
            return false;
        }

       
        if(!(soldCollection == artcollection_info.soldCollection))
        {
            cout << "Art Collections are not the same" << endl;
            return false;
        }


        cout << "Art Collections are the same" << endl;
        return true;

    }

    friend ArtCollection operator+(const ArtCollection& art_collection1, const ArtCollection& art_collection2);
     
     /**
     * @brief Additional function to help Overloaded Operator+
     * @param SoldArtwork 
     * Checks for suplication in SoldCollection, adds if not duplicated.
     * */

    void append(const SoldArtwork sold_item)
    {
        
        // Check for duplication
        bool duplicated = false;

        for( int i = 0 ; i < soldCollection.size(); i++)
        {
            if(soldCollection[i] == sold_item)
            {
                bool duplicated = true;
            }
        }

        if(!duplicated)
        {
            soldCollection.push_back(sold_item);
        }
    }

};

/**
* @brief Overloaded Operator (Non-member friend function)
* @param ArtCollection art_collection1
* @param ArtCollection art_collection2
* @return ArtCollection instance with Artwork and SoldArtwork included
* */

ArtCollection operator+(const ArtCollection& art_collection1, const ArtCollection& art_collection2 )
{ 
    ArtCollection Collection(art_collection1); 

    for( int i = 0 ; i < art_collection2.artCollection.size(); i++)
    {
        Collection.insert_artwork(art_collection2.artCollection[i]);
        
    }

    for( int j = 0 ; j < art_collection2.soldCollection.size(); j++)
    {
        bool added = true;
        added = Collection.sell_artwork(art_collection2.soldCollection[j]);

        if(!added)
        {
          Collection.append(art_collection2.soldCollection[j]);
        }
    }

    return Collection;
}


/**
 * Class to Test Functions of Artwork Class
 **/

class ArtCollection_Test {

public:

    bool test_artwork_constr() 
    {
        Artwork art_test;
        ASSERT_TRUE( art_test.getArtistName() == "")
        ASSERT_TRUE( art_test.getArtTitle() == "")
        ASSERT_TRUE( art_test.getYearMade() == 0)

        Artwork art_test2( "Adrian", 2000 , "MTE140 ART");
        ASSERT_TRUE( art_test2.getArtistName() == "Adrian")
        ASSERT_TRUE( art_test2.getArtTitle() == "MTE140 ART")
        ASSERT_TRUE( art_test2.getYearMade() == 2000)

        return true;
    }

    bool test_soldartwork_constr() 
    {
        SoldArtwork sold_test;
        ASSERT_TRUE( sold_test.getCustomerName() == "")
        ASSERT_TRUE( sold_test.getCustomerAddress() == "")
        ASSERT_TRUE( sold_test.getCost() == 0)

        
        Artwork art_test2( "Adrian", 2000 , "MTE140 ART");
        SoldArtwork sold_test2( "Chow", "Bridgeport" , 20000.0 , art_test2);
        ASSERT_TRUE( sold_test2.getCustomerName() == "Chow")
        ASSERT_TRUE( sold_test2.getCustomerAddress() == "Bridgeport")
        ASSERT_TRUE( sold_test2.getCost() == 20000.0)
        ASSERT_TRUE( sold_test2.getArtistName() == "Adrian")
        ASSERT_TRUE( sold_test2.getYearMade() == 2000)
        ASSERT_TRUE( sold_test2.getArtTitle() == "MTE140 ART")

        return true;
    }

    bool test_operator_artwork()
    {
        Artwork compareA("A",2020,"A");
        Artwork compareB("B",2020,"B");
        ASSERT_TRUE(compareA == compareA)
        ASSERT_FALSE(compareA == compareB)

        return true;
    }

    bool test_operator_soldartwork()
    {   
        Artwork fill;
        SoldArtwork compareA("A","A",20, fill);
        SoldArtwork compareB("A","B",220, fill);
        ASSERT_TRUE(compareA == compareA)
        ASSERT_FALSE(compareA == compareB)

        return true;
    }

    bool test_insert_artwork()
    {
        ArtCollection collection_test;
        Artwork A("Adrian",2020,"Ada");
        Artwork B("Billy",2000,"Brad");

        //INSERT TEST
        ASSERT_TRUE(collection_test.insert_artwork(A));
        // DUPLICATE TEST
        ASSERT_FALSE(collection_test.insert_artwork(A));
        //INSERT AGAIN
        ASSERT_TRUE(collection_test.insert_artwork(B));

        return true;
    
    }   
    
    bool test_sell_artwork()
    {
        ArtCollection collection_test;
        Artwork A("Adrian",2020,"Ada");
        Artwork B("Billy",2000,"Brad");
        Artwork C("Cassie",2010, "Cameron");
        

        SoldArtwork D("Bye", "There" , 12.0 , A);
        SoldArtwork F("Hi", "There" , 21.0 , B);


        collection_test.insert_artwork(A);
        collection_test.insert_artwork(C);
        

        //SELL TEST
        ASSERT_TRUE(collection_test.sell_artwork(D));
        //SELL ARTWORK - TWICE
        ASSERT_FALSE(collection_test.sell_artwork(D));
        //SELL ARTWORK - NOT THERE
        ASSERT_FALSE(collection_test.sell_artwork(F));

        return true;

    }

    bool test_operator_artcollection_equal()
    {
        ArtCollection collection_test;
        Artwork A("Adrian",2020,"Ada");
        Artwork B("Billy",2000,"Brad");
        Artwork C("Cassie",2010, "Cameron");
        SoldArtwork D("A","B",20.00, B);

        ArtCollection collection_test2;
        Artwork A1("Adrian",2020,"Ada");
        Artwork B2("Billy",2000,"Brad");
        Artwork C3("Cassie",2010, "Cameron");
        SoldArtwork D4("A","B",20.00, B2);

        SoldArtwork D5("e","v",50.00, C3);

        collection_test.insert_artwork(A);
        collection_test.insert_artwork(B);
        collection_test.insert_artwork(C);
        collection_test2.insert_artwork(A1);
        collection_test2.insert_artwork(B2);
        collection_test2.insert_artwork(C3);

        collection_test.sell_artwork(D);
        collection_test2.sell_artwork(D4);

        ASSERT_TRUE(collection_test == collection_test2)

        collection_test2.sell_artwork(D5);

        ASSERT_FALSE(collection_test == collection_test2)

        return true;

    }

    bool test_operator_artcollection_add()
    {
        ArtCollection collection_test;
        Artwork A("Adrian",2020,"Ada");
        Artwork B("Billy",2000,"Brad");
        Artwork C("Cassie",2010, "Cameron");
        SoldArtwork D("A","B",20.00, B);
        collection_test.insert_artwork(A);
        collection_test.insert_artwork(B);
        collection_test.insert_artwork(C);
        collection_test.sell_artwork(D);

        ArtCollection collection_test2;
        Artwork A1("A",1,"D");
        Artwork B2("B",2,"C");
        Artwork C3("E",3, "F");
        SoldArtwork D4("X","Y",50.00, B2);
        collection_test2.insert_artwork(A1);
        collection_test2.insert_artwork(B2);
        collection_test2.insert_artwork(C3);
        collection_test2.sell_artwork(D4);


        ArtCollection Answer;
        Answer.insert_artwork(A);
        Answer.insert_artwork(B);
        Answer.insert_artwork(C);
        Answer.sell_artwork(D);
        Answer.insert_artwork(A1);
        Answer.insert_artwork(B2);
        Answer.insert_artwork(C3);
        Answer.sell_artwork(D4);

        ArtCollection empty;
    
        //Equal Case
        ArtCollection test = collection_test + collection_test2;
        ASSERT_TRUE( test == Answer)

        //Empty Case
        ASSERT_TRUE( collection_test2 == (collection_test2 + empty))
        
        return true;

    }

    void run_test()
    {
        cout << (test_artwork_constr() ? "Test Increment Scenario1 Passed" : 
            "Test Increment Scenario1 Failed") << endl; 

        cout << (test_soldartwork_constr() ? "Test Increment Scenario2 Passed" : 
            "Test Increment Scenario2 Failed") << endl; 

        cout << (test_operator_artwork() ? "Test Increment Scenario3 Passed" : 
            "Test Increment Scenario3 Failed") << endl; 

        cout << (test_operator_soldartwork() ? "Test Increment Scenario4 Passed" : 
            "Test Increment Scenario4 Failed") << endl;    

        cout << (test_insert_artwork() ? "Test Increment Scenario5 Passed" : 
            "Test Increment Scenario5 Failed") << endl; 

        cout << (test_sell_artwork() ? "Test Increment Scenario6 Passed" : 
            "Test Increment Scenario6 Failed") << endl;    

        cout << (test_operator_artcollection_equal() ? "Test Increment Scenario7 Passed" : 
            "Test Increment Scenario7 Failed") << endl;  

        cout << (test_operator_artcollection_add() ? "Test Increment Scenario8 Passed" : 
            "Test Increment Scenario8 Failed") << endl;    
  

    }

};


int main()
{
    ArtCollection_Test test;
    test.run_test();    
  
    return 0;
}